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

    Q_PROPERTY(double mae READ mae NOTIFY maeChanged)
    Q_PROPERTY(double mape READ mape NOTIFY mapeChanged)
    Q_PROPERTY(double mse READ mse NOTIFY mseChanged)
    Q_PROPERTY(double rmse READ rmse NOTIFY rmseChanged)

    Q_PROPERTY(double mae2 READ mae2 NOTIFY mae2Changed)
    Q_PROPERTY(double mape2 READ mape2 NOTIFY mape2Changed)
    Q_PROPERTY(double mse2 READ mse2 NOTIFY mse2Changed)
    Q_PROPERTY(double rmse2 READ rmse2 NOTIFY rmse2Changed)

public:
    explicit ModelAnalysisV2(QObject *parent = nullptr, const std::vector<DataRow2>& data = {});

    double mae() const;
    double mape() const;
    double mse() const;
    double rmse() const;

    double mae2() const;
    double mape2() const;
    double mse2() const;
    double rmse2() const;

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

    double m_MAE;
    double m_MAPE;
    double m_MSE;
    double m_RMSE;

    double m_MAE2;
    double m_MAPE2;
    double m_MSE2;
    double m_RMSE2;

};

#endif // MODELANALYSISV2_H
