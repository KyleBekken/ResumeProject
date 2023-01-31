#include "CSVWriter.h"

#include <fstream>
#include <iostream>
#include <string>

#include "CO2Tracker.h"

void CSVWriter::DeleteCSV() { remove("results.csv"); }

void CSVWriter::UpdateCSV() {
  std::fstream fout;
  fout.open("results.csv", std::ios::out | std::ios::app);
  fout << CO2Tracker::GetInstance().GetTotalCO2() << ", "
       << CO2Tracker::GetInstance().GetAstarCO2() << ", "
       << CO2Tracker::GetInstance().GetBeelineCO2() << ", "
       << CO2Tracker::GetInstance().GetDFSCO2() << ", "
       << CO2Tracker::GetInstance().GetDijkstraCO2() << "\n";
  fout.close();
}