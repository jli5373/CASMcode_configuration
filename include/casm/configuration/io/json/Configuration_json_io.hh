#ifndef CASM_config_Configuration_json_io
#define CASM_config_Configuration_json_io

#include <map>
#include <memory>
#include <set>

namespace CASM {
namespace config {
struct Configuration;
class ConfigurationSet;
struct Prim;
class SupercellSet;
}  // namespace config

class jsonParser;
template <typename T>
class InputParser;

void from_json(config::SupercellSet &supercells,
               config::ConfigurationSet &configurations, jsonParser const &json,
               std::shared_ptr<config::Prim const> const &prim);

jsonParser &to_json(config::ConfigurationSet const &configurations,
                    jsonParser &json);

template <typename T>
struct jsonConstructor;
template <typename T>
struct jsonMake;
class jsonParser;

template <>
struct jsonConstructor<config::Configuration> {
  /// Read Configuration from JSON
  static config::Configuration from_json(
      jsonParser const &json, std::shared_ptr<config::Prim const> const &prim);
};

template <>
struct jsonMake<config::Configuration> {
  /// Read Configuration from JSON
  static std::unique_ptr<config::Configuration> make_from_json(
      jsonParser const &json, std::shared_ptr<config::Prim const> const &prim);
};

/// Insert Configuration to JSON
jsonParser &to_json(config::Configuration const &configuration,
                    jsonParser &json);

/// Parser Configuration from JSON with error messages
void parse(InputParser<config::Configuration> &parser,
           std::shared_ptr<config::Prim const> const &prim);

/// Parser Configuration from JSON with error messages
void parse(InputParser<config::Configuration> &parser,
           config::SupercellSet &supercells);

}  // namespace CASM

#endif
