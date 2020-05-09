#include <iostream>
#include <memory>
#include <vector>

#include "Op.hpp"

int main() {
  auto mkldnn = std::make_unique<mkldnnNode>("MklDnn");
  auto ngraphNormal = std::make_unique<ngraphNode>("NGraph", false);
  auto ngraphCaps = std::make_unique<ngraphNode>("NGraphCaps", true);

  auto parsers = std::vector<std::unique_ptr<NodeParser>>{};
  parsers.push_back(std::move(mkldnn));
  parsers.push_back(std::move(ngraphNormal));
  parsers.push_back(std::move(ngraphCaps));

  for (auto&parser : parsers) {
    const auto simple = SimpleOp(parser.get());
    std::cout << simple.getLowered();

    const auto normal = NormalOp(parser.get());
    std::cout << normal.getLowered();

    const auto mega = MEGAOp(parser.get());
    std::cout << mega.getLowered();

    std::cout << "\n";
  }
  return 0;
}
