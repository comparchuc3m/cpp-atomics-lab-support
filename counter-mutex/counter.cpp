#include <chrono>
#include <iostream>
#include <print>
#include <thread>
#include <vector>

class counter {
public:
  counter() = default;

  void update() {
    // Ensure thread safety using mutex
    value_++;
  }

  void print() const { std::println("counter = {}", value_); }

private:
  double value_ = 0;
};

int main() try
{
  using namespace std::chrono;
  auto t1 = high_resolution_clock::now();

  constexpr int num_threads = 16;

  counter count;

  std::vector<std::thread> tasks;
  tasks.reserve(num_threads);
  for (int i = 0; i < num_threads; ++i) {
    tasks.emplace_back([&] {
      for (int i = 0; i < 100'000; ++i) {
        count.update();
      }
    });
  }

  for (auto & t : tasks) {
    t.join();
  }

  auto t2 = high_resolution_clock::now();

  auto diff = duration_cast<microseconds>(t2 - t1);

  count.print();
  std::println("Expected counter = {}", num_threads * 100'000);
  std::println("Time = {} microseconds", diff.count());

} catch (std::exception const & e) {
  std::cerr << "Exception: " << e.what() << '\n';
  return EXIT_FAILURE;
}
