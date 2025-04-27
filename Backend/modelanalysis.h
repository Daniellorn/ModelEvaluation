#ifndef MODELANALYSIS_H
#define MODELANALYSIS_H

#include <QObject>
#include <QVariant>
#include <QPointF>
#include <QList>

#include "Csvreader.h"

class ModelAnalysis : public QObject
{
    Q_OBJECT


    Q_PROPERTY(double accuracy READ accuracy NOTIFY accuracyChanged)
    Q_PROPERTY(double specifity READ specifity NOTIFY specifityChanged)
    Q_PROPERTY(double recall READ recall NOTIFY recallChanged)
    Q_PROPERTY(double precision READ precision NOTIFY precisionChanged)
    Q_PROPERTY(double f1 READ f1 NOTIFY f1Changed)

    Q_PROPERTY(double accuracy2 READ accuracy2 NOTIFY accuracy2Changed)
    Q_PROPERTY(double specifity2 READ specifity2 NOTIFY specifity2Changed)
    Q_PROPERTY(double recall2 READ recall2 NOTIFY recall2Changed)
    Q_PROPERTY(double precision2 READ precision2 NOTIFY precision2Changed)
    Q_PROPERTY(double f12 READ f12 NOTIFY f12Changed)

    Q_PROPERTY(double tp READ tp NOTIFY tpChanged)
    Q_PROPERTY(double tn READ tn NOTIFY tnChanged)
    Q_PROPERTY(double fp READ fp NOTIFY fpChanged)
    Q_PROPERTY(double fn READ fn NOTIFY fnChanged)

    Q_PROPERTY(double tp2 READ tp2 NOTIFY tp2Changed)
    Q_PROPERTY(double tn2 READ tn2 NOTIFY tn2Changed)
    Q_PROPERTY(double fp2 READ fp2 NOTIFY fp2Changed)
    Q_PROPERTY(double fn2 READ fn2 NOTIFY fn2Changed)

    Q_PROPERTY(double auc READ auc NOTIFY aucChanged)
    Q_PROPERTY(double auc2 READ auc2 NOTIFY auc2Changed)


public:
    explicit ModelAnalysis(QObject* parent = nullptr, const std::vector<DataRow>& data = {});

    double accuracy() const;
    double specifity() const;
    double recall() const;
    double precision() const;
    double f1() const;

    double accuracy2() const;
    double specifity2() const;
    double recall2() const;
    double precision2() const;
    double f12() const;

    double tp() const;
    double tn() const;
    double fp() const;
    double fn() const;

    double tp2() const;
    double tn2() const;
    double fp2() const;
    double fn2() const;

    double auc() const;
    double auc2() const;

    void CalculateROCPoints1();
    void CalculateROCPoints2();

    Q_INVOKABLE void calculate();

    Q_INVOKABLE QVariantList getROCPoints() const;
    Q_INVOKABLE QVariantList getROCPoints2() const;


    void SetData(std::vector<DataRow>& data);

signals:
    void accuracyChanged();
    void specifityChanged();
    void recallChanged();
    void precisionChanged();
    void f1Changed();

    void accuracy2Changed();
    void specifity2Changed();
    void recall2Changed();
    void precision2Changed();
    void f12Changed();

    void tpChanged();
    void tnChanged();
    void fpChanged();
    void fnChanged();

    void tp2Changed();
    void tn2Changed();
    void fp2Changed();
    void fn2Changed();

    void rocPointsReady();
    void aucChanged();

    void rocPoints2Ready();
    void auc2Changed();

private:

    void CalculateMatrix();
    void CalculateAccuracy();
    void CalculateSpecifity();
    void CalculateRecall();
    void CalculatePrecision();
    void CalculateF1();
    void CalculateAUC();

private:
    std::vector<DataRow> m_FileData;

    QList<QPointF> m_ROCPoints;
    QList<QPointF> m_ROCPoints2;

    double m_TP;
    double m_TN;
    double m_FP;
    double m_FN;

    double m_TP2;
    double m_TN2;
    double m_FP2;
    double m_FN2;

    double m_accuracy;
    double m_specifity;
    double m_recall;
    double m_precision;
    double m_F1;

    double m_accuracy2;
    double m_specifity2;
    double m_recall2;
    double m_precision2;
    double m_F12;

    double m_AUC;
    double m_AUC2;
};

#endif // MODELANALYSIS_H
