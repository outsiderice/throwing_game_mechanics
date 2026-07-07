#include "Player.hpp"

Player::Player(void) : _body({(float)GetScreenWidth()/2-30, 300, 60, 80}), _isHolding(false)
{
	return ;
}

void	Player::setPosition(float direction)
{
	float	speed = 4.0f;
	_body.x += speed * direction;

	_body.x = Clamp(_body.x, 0, (float)GetScreenWidth() - _body.width);
	return ;
}


Rectangle	Player::getBody(void) const
{
	return (_body);
}

void	Player::downArrowAction(bool collision, Rectangle *object)
{
	if (_isHolding == true)
	{
		*object = {getBody().x, 350, 30, 50};
		_isHolding = false;
	}
	else if (collision)
	{
		*object = {getBody().x, getBody().y, 30, 50};
		_isHolding = true;
	}
	return ;
}
