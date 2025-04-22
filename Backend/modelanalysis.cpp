#include "modelanalysis.h"

#include <QDebug>
#include <algorithm>

ModelAnalysis::ModelAnalysis(QObject* parent, const std::vector<DataRow>& data):
    QObject(parent), m_FileData(data)
{
    m_TP = 0.0;
    m_TN = 0.0;
    m_FP = 0.0;
    m_FN = 0.0;

    m_accuracy = 0.0;
    m_specifity = 0.0;
    m_recall = 0.0;
    m_precision = 0.0;
    m_F1 = 0.0;
}

float ModelAnalysis::accuracy() const
{
    return m_accuracy;
}

float ModelAnalysis::specifity() const
{
    return m_specifity;
}

float ModelAnalysis::recall() const
{
    return m_recall;
}

float ModelAnalysis::precision() const
{
    return m_precision;
}

float ModelAnalysis::f1() const
{
    return m_F1;
}

float ModelAnalysis::tp() const
{
    return m_TP;
}

float ModelAnalysis::tn() const
{
    return m_TN;
}

float ModelAnalysis::fp() const
{
    return m_FP;
}

float ModelAnalysis::fn() const
{
    return m_FN;
}

void ModelAnalysis::CalculateROCPoints1()
{
    std::vector<DataRow> temp = m_FileData;

    std::sort(temp.begin(), temp.end(), [](const DataRow& a, const DataRow& b)
              {
                    return a.C50_prob1 > b.C50_prob1;
    });


    m_ROCPoints.append(QPointF(0.0, 0.0));

    for (int i = 0; i < temp.size(); i++)
    {
        float threshold = temp[i].C50_prob1;

        float TP = 0, FP = 0, TN = 0, FN = 0;

        for (int j = 0; j < temp.size(); j++)
        {
            bool predicted = temp[j].C50_prob1 >= threshold;
            bool actual = temp[j].income == 1;

            if (predicted && actual)
            {
                TP++;
            }
            else if (predicted && !actual)
            {
                FP++;
            }
            else if (!predicted && !actual)
            {
                TN++;
            }
            else if (!predicted && actual)
            {
                FN++;
            }
        }

        float recall = (TP + FN) > 0 ? TP / (TP + FN) : 0.0;
        float fpr = (FP + TN) > 0 ? FP / (FP + TN) : 0.0;


        //qDebug() << fpr << " " << recall << "\n";
        m_ROCPoints.append(QPointF(fpr, recall));
    }



    emit rocPointsReady();
}

void ModelAnalysis::calculate()
{
    CalculateMatrix();
    CalculateAccuracy();
    CalculateSpecifity();
    CalculateRecall();
    CalculatePrecision();
    CalculateF1();
    CalculateROCPoints1();

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
}

void ModelAnalysis::CalculateAccuracy()
{
    qDebug() << m_TN << " " << m_TP << " " << m_FN << " " << m_FP << "\n";

    m_accuracy = (m_TN + m_TP) / (m_TN + m_TP + m_FN + m_FP) * 100.0;
}

void ModelAnalysis::CalculateSpecifity()
{
    m_specifity = m_TN / (m_TN + m_FP) * 100.0;
}

void ModelAnalysis::CalculateRecall()
{
    m_recall = m_TP / (m_FN + m_TP) * 100.0;
}

void ModelAnalysis::CalculatePrecision()
{
    m_precision = m_TP / (m_FP + m_TP) * 100.0;
}

void ModelAnalysis::CalculateF1()
{
    m_F1 = 2 * (m_recall * m_precision) / (m_recall + m_precision);
}


