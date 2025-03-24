#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

class BitcoinExchange {
private:
  std::map<std::string, float> exchangeRates;

public:
  BitcoinExchange();
  BitcoinExchange(const std::string &databaseFile);
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);
  ~BitcoinExchange();

  void loadDatabase(const std::string &filename);
  float getExchangeRate(const std::string &date) const;
  bool isValidDate(const std::string &date) const;
  float processInput(const std::string &date, float value) const;
  void processInputFile(const std::string &filename) const;
};