//
// Created by jnannie on 12/22/20.
//

#include "Enemy.hpp"

Enemy::Enemy() : _hp(0), _type("") {

}

Enemy::Enemy(int hp, std::string const &type) : _hp(hp), _type(type) {

}

Enemy::Enemy(Enemy const &other) {
	*this = other;
}

Enemy &Enemy::operator=(Enemy const &other) {
	if (this != &other)
	{
		this->_hp = other._hp;
		this->_type = other._type;
	}
	return (*this);
}

Enemy::~Enemy() {

}

std::string const &Enemy::getType() const {
	return (this->_type);
}

int Enemy::getHp() const {
	return (this->_hp);
}

void Enemy::takeDamage(int damage) {
	this->_hp -= damage;
	if (this->_hp < 0)
		this->_hp = 0;
}
