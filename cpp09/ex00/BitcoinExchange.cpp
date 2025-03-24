#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &databaseFile) {
  loadDatabase(databaseFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
    : exchangeRates(other.exchangeRates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this != &other) {
    exchangeRates = other.exchangeRates;
  }
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string &filename) {
  std::ifstream file(filename.c_str());
  if (!file.is_open()) {
    throw std::runtime_error("Error: could not open file.");
  }

  std::string line;
  std::getline(file, line);

  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::string date;
    float rate;

    if (std::getline(iss, date, ',') && iss >> rate) {
      exchangeRates[date] = rate;
    }
  }
}

float BitcoinExchange::getExchangeRate(const std::string &date) const {
  // upper_bound(date)finds the first element strictly greater than the given
  // date, lower_bound(date) finds the first element greater than or equal to
  // the given date ???
  auto it = exchangeRates.upper_bound(date);

  if (it == exchangeRates.begin()) {
    throw std::runtime_error("Error: no exchange rate for this date");
  }
  --it;
  return it->second;
}

bool BitcoinExchange::isValidDate(const std::string &date) const {
  if (date.length() != 10)
    return false;

  if (date[4] != '-' || date[7] != '-')
    return false;

  try {
    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
      return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
      return false;

    if (month == 2) {
      bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
      if (day > (isLeap ? 29 : 28))
        return false;
    }
    return true;
  } catch (const std::exception &) {
    return false;
  }
}

float BitcoinExchange::processInput(const std::string &date,
                                    float value) const {
  if (!isValidDate(date)) {
    throw std::runtime_error("Error: bad input => " + date);
  }

  if (value < 0) {
    throw std::runtime_error("Error: not a positive number.");
  } else if (value > 1000) {
    throw std::runtime_error("Error: too large a number.");
  }

  return value * getExchangeRate(date);
}

void BitcoinExchange::processInputFile(const std::string &filename) const {
  std::ifstream file(filename.c_str());
  if (!file.is_open()) {
    throw std::runtime_error("Error: could not open file.");
  }
  std::string line;
  std::getline(file, line);
  if (line != "date | value")
    std::cout << "Warning: Unexpected header format" << std::endl;

  while (std::getline(file, line)) {
    size_t pipePos = line.find(" | ");
    if (pipePos == std::string::npos) {
      std::cout << "Error: bad input => " << line << std::endl;
      continue;
    }
    std::string date = line.substr(0, pipePos);
    std::string valueStr = line.substr(pipePos + 3);

    try {
      size_t idx;
      float value = std::stof(valueStr, &idx);
      if (idx != valueStr.length()) {
        std::cout << "Error: bad input => " << line << std::endl;
        continue;
      }
      try {
        float result = processInput(date, value);
        std::cout << date << " => " << value << " = " << result << std::endl;
      } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
      }
    } catch (const std::exception &) {
      std::cout << "Error: bad input => " << line << std::endl;
    }
  }
}
