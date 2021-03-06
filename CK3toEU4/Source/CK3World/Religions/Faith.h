#ifndef CK3_FAITH_H
#define CK3_FAITH_H
#include "Parser.h"
#include "Color.h"
#include <set>

extern commonItems::Color::Factory laFabricaDeColor;

namespace CK3
{
class Religion;
class Faith: commonItems::parser
{
  public:
	Faith() = default;
	Faith(std::istream& theStream, long long theID);

	[[nodiscard]] const auto& getName() const { return tag; }
	[[nodiscard]] const auto& getColor() const { return color; }
	[[nodiscard]] const auto& getDoctrines() const { return doctrines; }
	[[nodiscard]] const auto& getReligion() const { return religion; }
	[[nodiscard]] auto getID() const { return ID; }
	[[nodiscard]] const auto& getCustomName() const { return customName; }
	[[nodiscard]] const auto& getCustomAdj() const { return customAdjective; }
	[[nodiscard]] const auto& getDescription() const { return description; }
	[[nodiscard]] const auto& getTemplate() const { return religionTemplate; }
	[[nodiscard]] const auto& getIconPath() const { return iconPath; }

	void loadReligion(const std::pair<long long, std::shared_ptr<Religion>>& theReligion) { religion = theReligion; }

  private:
	void registerKeys();

	long long ID = 0;
	std::string tag;
	std::string religionTemplate;
	std::string iconPath;
	std::string customName;
	std::string customAdjective;
	std::string description;
	std::optional<commonItems::Color> color;
	std::set<std::string> doctrines;
	std::pair<long long, std::shared_ptr<Religion>> religion;
};
} // namespace CK3

#endif // CK3_FAITH_H
