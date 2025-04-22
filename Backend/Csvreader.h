#ifndef CSVREADER_H
#define CSVREADER_H

#include <filesystem>
#include <vector>

#include <QObject>

struct DataRow {

    int income;
    int C50_PV;
    float C50_prob1;
    int rf_PV;
    float rf_prob1;
};

class CSVReader: public QObject
{
    Q_OBJECT


public:
    CSVReader();

    std::vector<DataRow>& GetData();
    void PrintData();
    void PrintPath();

signals:
    void fileLoaded(std::vector<DataRow>& data);

public slots:

    void loadFileSlot(const QString& filePath);

private:
    void LoadFile(const std::filesystem::path& path);
    int EncodeValues(const std::string& value);

private:
    std::filesystem::path m_Path;
    std::vector<DataRow> m_Data;

};

#endif // CSVREADER_H
