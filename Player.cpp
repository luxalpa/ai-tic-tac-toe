#include "Player.h"
#include "Game.h"

Player *Player::NoPlayer = new Player(PlayerIcon::None);

Player::Player()
{

}

Player::~Player()
{

}

Player::Player(PlayerIcon icon)
{
    m_icon = icon;
}

PlayerIcon Player::icon() const
{
    return m_icon;
}

bool Player::isLocal() const
{
    return m_local; // TODO: implement!
}

void Player::setLocal(bool local)
{
    m_local = local;
}

void Player::process()
{
    // do nothing for human players
}

void Player::setIcon(const PlayerIcon& icon)
{
    m_icon = icon;
}

void Player::appendToGame(Game* g)
{
    this->game = g;
    this->map = game->map();
}


