#include "modelanalysis.h"

#include <QDebug>
#include <algorithm>
#include <tuple>
#include <execution>
#include <numeric>

ModelAnalysis::ModelAnalysis(QObject* parent, const std::vector<DataRow>& data):
    QObject(parent), m_FileData(data)
{
    m_TP = 0.0;
    m_TN = 0.0;
    m_FP = 0.0;
    m_FN = 0.0;

    m_TP2 = 0.0;
    m_TN2 = 0.0;
    m_FP2 = 0.0;
    m_FN2 = 0.0;

    m_accuracy = 0.0;
    m_specifity = 0.0;
    m_recall = 0.0;
    m_precision = 0.0;
    m_F1 = 0.0;

    m_accuracy2 = 0.0;
    m_specifity2 = 0.0;
    m_recall2 = 0.0;
    m_precision2 = 0.0;
    m_F12 = 0.0;
}

double ModelAnalysis::accuracy() const
{
    return m_accuracy;
}

double ModelAnalysis::specifity() const
{
    return m_specifity;
}

double ModelAnalysis::recall() const
{
    return m_recall;
}

double ModelAnalysis::precision() const
{
    return m_precision;
}

double ModelAnalysis::f1() const
{
    return m_F1;
}

double ModelAnalysis::accuracy2() const
{
    return m_accuracy2;
}

double ModelAnalysis::specifity2() const
{
    return m_specifity2;
}

double ModelAnalysis::recall2() const
{
    return m_recall2;
}

double ModelAnalysis::precision2() const
{
    return m_precision2;
}

double ModelAnalysis::f12() const
{
    return m_F12;
}

double ModelAnalysis::tp() const
{
    return m_TP;
}

double ModelAnalysis::tn() const
{
    return m_TN;
}

double ModelAnalysis::fp() const
{
    return m_FP;
}

double ModelAnalysis::fn() const
{
    return m_FN;
}

double ModelAnalysis::tp2() const
{
    return m_TP2;
}

double ModelAnalysis::tn2() const
{
    return m_TN2;
}

double ModelAnalysis::fp2() const
{
    return m_FP2;
}

double ModelAnalysis::fn2() const
{
    return m_FN2;
}

double ModelAnalysis::auc() const
{
    return m_AUC;
}

double ModelAnalysis::auc2() const
{
    return m_AUC2;
}

void ModelAnalysis::CalculateROCPoints1()
{
    auto temp = m_FileData;

    std::sort(temp.begin(), temp.end(), [](const DataRow& a, const DataRow& b)
              {
                    return a.C50_prob1 > b.C50_prob1;
    });


    m_ROCPoints.append(QPointF(0.0, 0.0));

    for (int i = 0; i < temp.size(); i++)
    {
        double threshold = temp[i].C50_prob1;

        auto [TP, FP, TN, FN] = std::transform_reduce(
            std::execution::par,
            temp.begin(), temp.end(),
            std::tuple<double, double, double, double>{0.0, 0.0, 0.0, 0.0 },
            [](const auto& a, const auto& b)
            {
                return std::tuple{
                    std::get<0>(a) + std::get<0>(b),
                    std::get<1>(a) + std::get<1>(b),
                    std::get<2>(a) + std::get<2>(b),
                    std::get<3>(a) + std::get<3>(b)

                };
            },
            [threshold](const DataRow& row) {

                bool predicted = row.C50_prob1 >= threshold;
                bool actual = row.income == 1;

                if (predicted && actual) return std::tuple{1.0, 0.0, 0.0, 0.0};
                if (predicted && !actual) return std::tuple{0.0, 1.0, 0.0, 0.0};
                if (!predicted && !actual) return std::tuple{0.0, 0.0, 1.0, 0.0};

                return std::tuple{0.0, 0.0, 0.0, 1.0};
            });



       // double TP = 0, FP = 0, TN = 0, FN = 0;

       // for (int j = 0; j < temp.size(); j++)
       // {
       //     bool predicted = temp[j].C50_prob1 >= threshold;
       //     bool actual = temp[j].income == 1;

       //     if (predicted && actual)
       //     {
       //         TP++;
       //     }
       //     else if (predicted && !actual)
       //     {
       //         FP++;
       //     }
       //     else if (!predicted && !actual)
       //     {
       //         TN++;
       //     }
       //     else if (!predicted && actual)
       //     {
       //         FN++;
       //     }
       // }

        double recall = (TP + FN) > 0 ? TP / (TP + FN) : 0.0;
        double fpr = (FP + TN) > 0 ? FP / (FP + TN) : 0.0;


        //qDebug() << fpr << " " << recall << "\n";
        m_ROCPoints.append(QPointF(fpr, recall));
    }



    //qDebug() << TP << " " << FP << " " << TN << " " << FN;

    emit rocPointsReady();
}

void ModelAnalysis::CalculateROCPoints2()
{

    auto temp = m_FileData;

    std::sort(temp.begin(), temp.end(), [](const DataRow& a, const DataRow& b)
              {
                  return a.rf_prob1 > b.rf_prob1;
              });


    m_ROCPoints2.append(QPointF(0.0, 0.0));

    for (int i = 0; i < temp.size(); i++)
    {
        double threshold = temp[i].rf_prob1;

        auto [TP, FP, TN, FN] = std::transform_reduce(
            std::execution::par,
            temp.begin(), temp.end(),
            std::tuple<double, double, double, double>{0.0, 0.0, 0.0, 0.0 },
            [](const auto& a, const auto& b)
            {
                return std::tuple{
                    std::get<0>(a) + std::get<0>(b),
                    std::get<1>(a) + std::get<1>(b),
                    std::get<2>(a) + std::get<2>(b),
                    std::get<3>(a) + std::get<3>(b)

                };
            },
            [threshold](const DataRow& row) {

                bool predicted = row.rf_prob1 >= threshold;
                bool actual = row.income == 1;

                if (predicted && actual) return std::tuple{1.0, 0.0, 0.0, 0.0};
                if (predicted && !actual) return std::tuple{0.0, 1.0, 0.0, 0.0};
                if (!predicted && !actual) return std::tuple{0.0, 0.0, 1.0, 0.0};

                return std::tuple{0.0, 0.0, 0.0, 1.0};
            });



        // double TP = 0, FP = 0, TN = 0, FN = 0;

        // for (int j = 0; j < temp.size(); j++)
        // {
        //     bool predicted = temp[j].C50_prob1 >= threshold;
        //     bool actual = temp[j].income == 1;

        //     if (predicted && actual)
        //     {
        //         TP++;
        //     }
        //     else if (predicted && !actual)
        //     {
        //         FP++;
        //     }
        //     else if (!predicted && !actual)
        //     {
        //         TN++;
        //     }
        //     else if (!predicted && actual)
        //     {
        //         FN++;
        //     }
        // }

        double recall = (TP + FN) > 0 ? TP / (TP + FN) : 0.0;
        double fpr = (FP + TN) > 0 ? FP / (FP + TN) : 0.0;

        m_ROCPoints2.append(QPointF(fpr, recall));
    }



    emit rocPoints2Ready();
}

void ModelAnalysis::calculate()
{
    CalculateMatrix();
    CalculateAccuracy();
    CalculateSpecifity();
    CalculateRecall();
    CalculatePrecision();
    CalculateF1();

    //qDebug() << m_accuracy << " " << m_specifity << " " << m_recall << " " << m_precision << " " << m_F1 << "\n";

    emit accuracyChanged();
    emit specifityChanged();
    emit recallChanged();
    emit precisionChanged();
    emit f1Changed();

    emit tpChanged();
    emit tnChanged();
    emit fpChanged();
    emit fnChanged();

    emit accuracy2Changed();
    emit specifity2Changed();
    emit recall2Changed();
    emit precision2Changed();
    emit f12Changed();

    emit tp2Changed();
    emit tn2Changed();
    emit fp2Changed();
    emit fn2Changed();


    CalculateROCPoints1();
    CalculateROCPoints2();
    CalculateAUC();
}

QVariantList ModelAnalysis::getROCPoints() const
{
    QVariantList list;

    for (const QPointF& point: m_ROCPoints)
    {
        list.append(QVariant::fromValue(point));
    }
    return list;
}

QVariantList ModelAnalysis::getROCPoints2() const
{
    QVariantList list;

    for (const QPointF& point: m_ROCPoints2)
    {
        list.append(QVariant::fromValue(point));
    }
    return list;
}

void ModelAnalysis::SetData(std::vector<DataRow>& data)
{
    m_FileData = data;
}

void ModelAnalysis::CalculateMatrix()
{
    for (auto& row: m_FileData)
    {
        if (row.income == 0 && row.C50_PV == 0)
        {
            m_TN += 1;
        }
        else if (row.income == 0 && row.C50_PV == 1)
        {
            m_FP += 1;
        }
        else if (row.income == 1 && row.C50_PV == 1)
        {
            m_TP += 1;
        }
        else if (row.income == 1 && row.C50_PV == 0)
        {
            m_FN += 1;
        }
    }

    for (auto& row: m_FileData)
    {
        if (row.income == 0 && row.rf_PV == 0)
        {
            m_TN2 += 1;
        }
        else if (row.income == 0 && row.rf_PV == 1)
        {
            m_FP2 += 1;
        }
        else if (row.income == 1 && row.rf_PV == 1)
        {
            m_TP2 += 1;
        }
        else if (row.income == 1 && row.rf_PV == 0)
        {
            m_FN2 += 1;
        }
    }
}

void ModelAnalysis::CalculateAccuracy()
{
    qDebug() << m_TN << " " << m_TP << " " << m_FN << " " << m_FP << "\n";

    m_accuracy = (m_TN + m_TP) / (m_TN + m_TP + m_FN + m_FP) * 100.0;
    m_accuracy2 = (m_TN2 + m_TP2) / (m_TN2 + m_TP2 + m_FN2 + m_FP2) * 100.0;
}

void ModelAnalysis::CalculateSpecifity()
{
    m_specifity = m_TN / (m_TN + m_FP) * 100.0;
    m_specifity2 = m_TN2 / (m_TN2 + m_FP2) * 100.0;
}

void ModelAnalysis::CalculateRecall()
{
    m_recall = m_TP / (m_FN + m_TP) * 100.0;
    m_recall2 = m_TP2 / (m_FN2 + m_TP2) * 100.0;
}

void ModelAnalysis::CalculatePrecision()
{
    m_precision = m_TP / (m_FP + m_TP) * 100.0;
    m_precision2 = m_TP2 / (m_FP2 + m_TP2) * 100.0;
}

void ModelAnalysis::CalculateF1()
{
    m_F1 = 2 * (m_recall * m_precision) / (m_recall + m_precision);
    m_F12 = 2 * (m_recall2 * m_precision2) / (m_recall2 + m_precision2);
}

void ModelAnalysis::CalculateAUC()
{
    double auc = 0.0;
    double auc2 = 0.0;

    for (int i = 1; i < m_ROCPoints.size(); i++)
    {
        double x1 = m_ROCPoints[i - 1].x();
        double y1 = m_ROCPoints[i - 1].y();
        double x2 = m_ROCPoints[i].x();
        double y2 = m_ROCPoints[i].y();

        auc += (x2 - x1) * (y1 + y2) / 2.0;
    }

    for (int i = 1; i < m_ROCPoints2.size(); i++)
    {
        double x1 = m_ROCPoints2[i - 1].x();
        double y1 = m_ROCPoints2[i - 1].y();
        double x2 = m_ROCPoints2[i].x();
        double y2 = m_ROCPoints2[i].y();

        auc2 += (x2 - x1) * (y1 + y2) / 2.0;
    }

    m_AUC = auc;
    m_AUC2 = auc2;
    emit aucChanged();
    emit auc2Changed();
}
