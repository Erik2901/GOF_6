#pragma once

#include <stdint.h>

#include "DestroyableGroundObject.h"
#include "Mediator.h"

class Tank : public DestroyableGroundObject
{
public:
	Tank();
	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }
	void Tank_Messsage() const;
	void Draw() const override;
	std::unique_ptr<Mediator> pMediator = std::make_unique<Mediator>();
private:
	std::vector<std::string> messages;
	const uint16_t score = 30;
};

