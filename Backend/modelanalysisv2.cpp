#include "modelanalysisv2.h"

ModelAnalysisV2::ModelAnalysisV2(QObject *parent, const std::vector<DataRow2>& data)
    : QObject{parent},  m_FileData2(data)
{

    m_MAE = 0.0f;
    m_MAPE = 0.0f;
    m_MSE = 0.0f;
    m_RMSE = 0.0f;

    m_MAE2 = 0.0f;
    m_MAPE2 = 0.0f;
    m_MSE2 = 0.0f;
    m_RMSE2 = 0.0f;

}

float ModelAnalysisV2::mae() const
{
    return m_MAE;
}

float ModelAnalysisV2::mape() const
{
    return m_MAPE;
}

float ModelAnalysisV2::mse() const
{
    return m_MSE;
}

float ModelAnalysisV2::rmse() const
{
    return m_RMSE;
}

float ModelAnalysisV2::mae2() const
{
    return m_MAE2;
}

float ModelAnalysisV2::mape2() const
{
    return m_MAPE2;
}

float ModelAnalysisV2::mse2() const
{
    return m_MSE2;
}

float ModelAnalysisV2::rmse2() const
{
    return m_RMSE2;
}

void ModelAnalysisV2::calculate2()
{
    CalculateRegression();
    CalculateRegression2();
}

void ModelAnalysisV2::SetData(std::vector<DataRow2> &data)
{
    m_FileData2 = data;
}

void ModelAnalysisV2::CalculateRegression()
{
    float sumAbs = 0.0f;
    float sumAbsPerc = 0.0f;
    float sumSq = 0.0f;

    for (const auto& row: m_FileData2)
    {
        float pred = row.expected1;
        float error = row.real - pred;

        sumAbs += std::abs(error);
        sumSq += error * error;

        if (row.real != 0.0f)
        {
            sumAbsPerc += std::abs(error / row.real);
        }
    }


    int n = m_FileData2.size();

    if (n > 0)
    {
        m_MAE = sumAbs / n;
        m_MSE = sumSq / n;
        m_RMSE = std::sqrt(m_MSE);
        m_MAPE = (sumAbsPerc / n) * 100.0f;
    }

    emit maeChanged();
    emit mapeChanged();
    emit mseChanged();
    emit rmseChanged();
}

void ModelAnalysisV2::CalculateRegression2()
{
    float sumAbs = 0.0f;
    float sumAbsPerc = 0.0f;
    float sumSq = 0.0f;

    for (const auto& row: m_FileData2)
    {
        float pred = row.expected2;
        float error = row.real - pred;

        sumAbs += std::abs(error);
        sumSq += error * error;

        if (row.real != 0.0f)
        {
            sumAbsPerc += std::abs(error / row.real);
        }
    }


    int n = m_FileData2.size();

    if (n > 0)
    {
        m_MAE2 = sumAbs / n;
        m_MSE2 = sumSq / n;
        m_RMSE2 = std::sqrt(m_MSE2);
        m_MAPE2 = (sumAbsPerc / n) * 100.0f;
    }

    emit mae2Changed();
    emit mape2Changed();
    emit mse2Changed();
    emit rmse2Changed();
}
