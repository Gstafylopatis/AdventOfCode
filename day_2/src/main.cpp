#include <iostream>
#include <fstream>

#define THRESHOLD 3

bool is_stable(int n1, int n2, int order)
{
  if (n1 == n2)
    return false;

  if ((n1 > n2 ? 1 : -1) != order)
  {
    return false;
  }

  if (abs(n1 - n2) > THRESHOLD)
    return false;

  return true;
}

/**
 * Checks if sequence is stable
 *
 * For each n1 and n2
 * If n1 == n2 -> Unstable
 * If n1 - n2 > Threshhold -> Unstable
 * If order changes -> Unstable
 *
 * @param Vector of Ints to compare
 * @return Bool -> True if stable, false otherwise
 */
bool is_sequence_stable(std::vector<int> numbers)
{
  int order;
  for (int i = 1; i < numbers.size(); i++)
  {
    if (i == 1)
      order = numbers[i] > numbers[i - 1] ? 1 : -1;

    if (!is_stable(numbers[i], numbers[i - 1], order))
      return false;
  }
  return true;
}

int main()
{
  int safe_reports = 0;

  // Open file
  std::ifstream input("../input.txt");
  if (!input.is_open())
  {
    std::cerr << "Error opening file" << std::endl;
    return -1;
  }

  std::string line;

  while (std::getline(input, line))
  {
    int faults_remaining = 1;
    int removed_index = -1;

    size_t pos = 0;
    std::vector<int> numbers;
    while ((pos = line.find(' ')) != std::string::npos)
    {
      numbers.emplace_back(atoi(line.substr(0, pos).c_str()));
      line.erase(0, pos + 1);
    }

    // push the last number
    numbers.emplace_back(atoi(line.c_str()));

    std::vector<int> numbers_original(numbers);

    int order; // 1 for asc, -1 for desc
    bool stable;

    order = numbers[1] > numbers[0] ? 1 : -1; // Get the order of the first elements as starting point
    int i = 1;
    do
    {

      stable = is_stable(numbers[i], numbers[i - 1], order);

      if (!stable && faults_remaining > 0)
      {
        faults_remaining = 0;

        for (int j = 0; j < numbers.size(); j++)
        {

          std::vector<int> temp_vec(numbers);
          // Try with i - 1 removed
          temp_vec.erase(temp_vec.begin() + j);

          if (is_sequence_stable(temp_vec))
          {
            removed_index = j;
            stable = true;
            break;
          }
        }
        break;
      }

      i++;
    } while (stable && i < numbers.size());

    for (int i : numbers_original)
    {
      std::cout << i << " ";
    }
    if (stable)
    {
      std::cout << ": Safe ";
      if (removed_index > -1)
        std::cout << "by removing level " << removed_index + 1 << " (" << numbers_original[removed_index] << ")";

      safe_reports++;

      std::cout << std::endl;
    }
    else
    {
      std::cout << ": Unsafe" << std::endl;
    }
  }

  std::cout << safe_reports << std::endl;
  return 0;
}
