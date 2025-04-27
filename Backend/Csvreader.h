#ifndef CSVREADER_H
#define CSVREADER_H

#include <filesystem>
#include <vector>
#include <string_view>

#include <QObject>

struct DataRow
{

    int income;
    int C50_PV;
    double C50_prob1;
    int rf_PV;
    double rf_prob1;
};

struct DataRow2
{
    double real;
    double expected1;
    double expected2;
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
    void fileLoaded2(std::vector<DataRow2>& data);

public slots:

    void loadFileSlot(const QString& filePath);

private:
    void LoadFile(const std::filesystem::path& path, std::string_view filename);
    int EncodeValues(const std::string& value);

private:
    std::filesystem::path m_Path;
    std::vector<DataRow> m_Data;
    std::vector<DataRow2> m_Data2;

};

#endif // CSVREADER_H
