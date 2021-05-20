#include <iostream>
#include <memory>
#include <atomic>
#include <vector>
#include <algorithm>

std::atomic<int64_t> kId = 0; // namespace, type, global variable, literal

#define LOG_DEBUG(message) std::cout << message << std::endl; // macro

class Entity 
{
public:
  struct Vec4 // type
  {
    float x = 0; // built-in type, member variables
    float y = 0;
    float z = 0;
    float w = 0;

    const Vec4& operator+=(const Vec4& vec) // member function, argument
    { 
      x += vec.x; // built-in operator
      y += vec.y;
      z += vec.z;
      w += vec.w;
      return *this;
    }
  };

  // member functions
  Entity(const std::string_view name, const Vec4& position) :
    mId(GenerateId()), mName(name), mPosition(position) {}

  void Move(const Vec4& position)
  {
    LOG_DEBUG("Moving entity " << mId << " by " << position.x << " " << position.y << " " << position.z);
    mPosition += position; // overloaded operator
  }

  const std::string& GetName() const
  {
    return mName;
  }

protected:
  // static member functions
  static int64_t GenerateId() { return kId++; } 

  // static member variables
  static constexpr std::string_view kName = "Entity"; 
  static constexpr int64_t kMaxCount = 1234; 

  // member variables
  int64_t mId = 0; 
  Vec4 mPosition;
  std::string mName;
};

int main() // function
try // try block
{
  // local variable
  static constexpr size_t kMaxEnemies = 100;
  Entity player("Player", {1, 2, 3, 4}); 
  player.Move(Entity::Vec4{4, 3, 2, 1});

  std::vector<std::shared_ptr<Entity>> enemies;
  enemies.emplace_back(std::make_shared<Entity>("Enemy 1", Entity::Vec4{1, 2, 3, 4}));
  enemies.emplace_back(std::make_shared<Entity>("Enemy 2", Entity::Vec4{1, 2, 3, 4}));

  if (std::any_of(enemies.begin(), enemies.end(), [](const auto& enemy) { return enemy->GetName() != "Bad"; }))
    throw std::runtime_error("These enemies are bad"); // throw

  if (enemies.empty() || enemies.size() >= kMaxEnemies && enemies.size() != 9)
    throw std::runtime_error("No enemies to work with"); // throw

  for (const auto& enemy : enemies)
    enemy->Move(Entity::Vec4{-6.1f, 5.3f, 4.0f, -3.6f});
}
catch (const std::exception& e) // catch block
{
  LOG_DEBUG("Error: " << e.what());
}