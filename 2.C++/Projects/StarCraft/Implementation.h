#pragma once
#ifndef IMPLEMENTATION_H
#define IMPLEMENTATION_H

typedef enum BATTLESHIP { Viking, BattleCruiser, Phoenix, Carrier };

class BattleShip
{
private:
	int m_health;
//	int m_shield;
//	int m_attack;

public:

	BattleShip();
	BattleShip(int& health, int& attack);
	BattleShip(int& health, int& shield, int& attack);
	virtual ~BattleShip();

	virtual void SetHealth(int health) = 0;
	virtual void SetShield(int shield) = 0;
	virtual void SetAttack(int attack) = 0;

	virtual int GetHealth() const = 0;
	virtual int GetShield() const = 0;
	virtual int GetAttack() const = 0;

};

BattleShip::BattleShip() {};
//BattleShip::BattleShip(int& health, int& attack) : m_health(health), m_shield(0), m_attack(attack) {};
//BattleShip::BattleShip(int& health, int& shield, int& attack) : m_health(health), m_shield(shield), m_attack(attack) {};
BattleShip::~BattleShip() {};

class Terran : public BattleShip
{
public:
	Terran();
	virtual ~Terran();
	virtual void SetHealth(int health);
	virtual void SetShield(int shield);
	virtual void SetAttack(int attack);
	BATTLESHIP& SetBattleShip(BATTLESHIP& ship);

	virtual int GetHealth() const;
	virtual int GetShield() const;
	virtual int GetAttack() const;
	BATTLESHIP& GetBattleShip() const;

private:
	BATTLESHIP ship;
};

Terran::Terran() {}
Terran::~Terran() {}

class Protoss : public BattleShip
{
public:
	Protoss();
	virtual ~Protoss();

private:
	BATTLESHIP ship;
};

Protoss::Protoss() {}
Protoss::~Protoss() {}
#endif // !IMPLEMENTATION_H
