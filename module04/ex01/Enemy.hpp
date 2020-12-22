//
// Created by jnannie on 12/22/20.
//

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>

class Enemy
{
private:
	int _hp;
	std::string _type;

public:
	Enemy();
	Enemy(int hp, std::string const &type);
	Enemy(Enemy const &other);
	Enemy &operator=(Enemy const &other);
	virtual ~Enemy();

	std::string const &getType() const;
	int getHp() const;
	virtual void takeDamage(int damage);
};


#endif //ENEMY_HPP
