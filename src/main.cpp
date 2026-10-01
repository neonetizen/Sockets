#include <iostream>

#include <asio.hpp>

asio::awaitable<void> hello(int n) {
  auto executor = co_await asio::this_coro::executor;
  asio::steady_timer timer(executor);

  for (auto i = 0; i < n; ++i) {
    timer.expires_after(static_cast<std::chrono::seconds>(i));
    co_await timer.async_wait(asio::use_awaitable);

    std::cout << "waited " << i << "s\n";
  }
}

int main() {
  asio::io_context io;

  asio::co_spawn(io, hello(3), asio::detached);

  io.run();
}