#pragma once

class NodeParser {
  virtual std::string name() const = 0;
  virtual std::string color() const = 0;
  virtual bool caps() const = 0;

public:
  std::string getName() const {
    std::cout << "getName ";
    return name();
  }
  std::string getColor() const {
    std::cout << "getColor ";
    return color();
  }
  bool isCaps() const {
    std::cout << "getCaps ";
    return caps();
  }
};

class mkldnnNode : public NodeParser {
  std::string nodeName;

  std::string name() const override { return nodeName; }
  std::string color() const override { return "\033[1;36m"; }
  bool caps() const override { return false; }

public:
  explicit mkldnnNode(std::string nodeName) : nodeName{nodeName} {}
};

class ngraphNode : public NodeParser {
  std::string nodeName;
  bool isCaps;

  std::string name() const override { return nodeName; }
  std::string color() const override { return "\033[1;32m"; }
  bool caps() const override { return isCaps; }

public:
  explicit ngraphNode(std::string nodeName, bool isCaps)
      : nodeName{nodeName}, isCaps{isCaps} {}
};
