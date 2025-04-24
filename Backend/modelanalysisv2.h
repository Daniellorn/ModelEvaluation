#ifndef MODELANALYSISV2_H
#define MODELANALYSISV2_H

#include <QObject>

#include <QObject>
#include <QVariant>
#include <QPointF>
#include <QList>

#include "Csvreader.h"

class ModelAnalysisV2 : public QObject
{
    Q_OBJECT

    Q_PROPERTY(float mae READ mae NOTIFY maeChanged)
    Q_PROPERTY(float mape READ mape NOTIFY mapeChanged)
    Q_PROPERTY(float mse READ mse NOTIFY mseChanged)
    Q_PROPERTY(float rmse READ rmse NOTIFY rmseChanged)

    Q_PROPERTY(float mae2 READ mae2 NOTIFY mae2Changed)
    Q_PROPERTY(float mape2 READ mape2 NOTIFY mape2Changed)
    Q_PROPERTY(float mse2 READ mse2 NOTIFY mse2Changed)
    Q_PROPERTY(float rmse2 READ rmse2 NOTIFY rmse2Changed)

public:
    explicit ModelAnalysisV2(QObject *parent = nullptr, const std::vector<DataRow2>& data = {});

    float mae() const;
    float mape() const;
    float mse() const;
    float rmse() const;

    float mae2() const;
    float mape2() const;
    float mse2() const;
    float rmse2() const;

    Q_INVOKABLE void calculate2();

    void SetData(std::vector<DataRow2>& data);

signals:
    void maeChanged();
    void mapeChanged();
    void mseChanged();
    void rmseChanged();

    void mae2Changed();
    void mape2Changed();
    void mse2Changed();
    void rmse2Changed();

private:
    void CalculateRegression();
    void CalculateRegression2();

private:
    std::vector<DataRow2> m_FileData2;

    float m_MAE;
    float m_MAPE;
    float m_MSE;
    float m_RMSE;

    float m_MAE2;
    float m_MAPE2;
    float m_MSE2;
    float m_RMSE2;

};

#endif // MODELANALYSISV2_H
