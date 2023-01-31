#ifndef CSVWRITER_H_
#define CSVWRITER_H_

#include <fstream>
#include <iostream>
#include <string>

#include "CO2Tracker.h"
#include "CSVWriter.h"

/**
 * @brief This class writes the emission data from the simulation to a CSV file.
 */
class CSVWriter {
 public:
  /**
   * @brief Static function that creates a CSV to write emission data to.
   */
  static void DeleteCSV();

  /**
   * @brief Static function that writes the emission data from the simulation to
   * a CSV file.
   */
  static void UpdateCSV();
};

#endif