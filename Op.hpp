#pragma once

#include "NodeParser.hpp"

std::string to_upper(const std::string &str) {
  std::string result;
  result.reserve(str.size());
  for (auto c : str) {
    result.push_back(std::toupper(c));
  }
  return result;
}

class Op {
protected:
  NodeParser *node{};

private:
  virtual std::string lower() const = 0;

public:
  std::string getLowered() const {
    std::cout << "getLowered ";
    return lower() + "\033[0m\n";
  };
};

class SimpleOp : public Op {
public:
  explicit SimpleOp(NodeParser *node) {
    std::cout << "SimpleOp ctor ";
    this->node = node;
  }
  std::string lower() const override {
    return node->isCaps() ? to_upper(node->getName()) : node->getName();
  }
};

class NormalOp : public Op {
public:
  explicit NormalOp(NodeParser *node) {
    std::cout << "NormalOp ctor ";
    this->node = node;
  }
  std::string lower() const override {
    const auto name =
        node->isCaps() ? to_upper(node->getName()) : node->getName();
    return node->getColor() + name;
  }
};

class MEGAOp : public Op {
public:
  explicit MEGAOp(NodeParser *node) {
    std::cout << "MEGAOp ctor ";
    this->node = node;
  }
  std::string lower() const override {
    return "\033[1;31m" + to_upper(node->getName());
  }
};