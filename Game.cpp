#include "Game.h"
#include <QSet>
#include <QDebug>
#include "AIPlayerRandom.h"
#include "AIPlayerDifficult.h"

Game::Game()
{
    m_map = GameMap(3, 3);
    reset();
    active = false;
}

Player* Game::addHumanPlayer()
{
    int id = m_players.size();
    PlayerIcon icon = (PlayerIcon)(id + 1);
    Player *player = new Player(icon);

    player->setLocal(true);
    player->appendToGame(this);

    m_players.append(player);
    return m_players.last();
}

Player* Game::addAIPlayer(Difficulty mode)
{
    int id = m_players.size();
    PlayerIcon icon = (PlayerIcon)(id + 1);
    Player *player;
    switch(mode) {
    case Difficulty::Perfect:
    case Difficulty::Easy:
    case Difficulty::Medium:
    case Difficulty::Hard:
        player = new AIPlayerDifficult(mode);
        break;
    case Difficulty::Random:
        player = new AIPlayerRandom();
        break;
    default:
        player = new Player();
        break;
    }

    player->setIcon(icon);
    player->setLocal(false);
    player->appendToGame(this);

    m_players.append(player);

    return m_players.last();
}

void Game::removeAllPlayers()
{
    qDeleteAll(m_players);
    m_players.clear();
}

GameMap* Game::map()
{
    return &m_map;
}

void Game::reset()
{
    map()->reset();
    curPlayerId = 0;
}

Player* Game::currentPlayer()
{
    if(m_players.size() == 0)
        return Player::NoPlayer;
    return m_players[curPlayerId];
}

PlayerIcon Game::currentPlayerIcon()
{
    return currentPlayer()->icon();
}

bool Game::activateField(QPoint pos) {
    return activateField(pos.x(), pos.y());
}

bool Game::activateField(int x, int y)
{
    if(map()->playerAt(x, y) != Player::NoPlayer) {
        return false;
    }
    map()->setField(x, y, currentPlayer());
    if(!checkWinner(x, y))
        nextTurn();
    return true;
}

bool Game::allowsInput()
{
    return isRunning() && currentPlayer()->isLocal();
}

bool Game::isRunning()
{
    return active;
}

void Game::start()
{
    reset();
    active = true;
}

void Game::end()
{
    active = false;
}

void Game::nextTurn()
{
    curPlayerId = (curPlayerId + 1) % m_players.size();
    currentPlayer()->process();
}

bool Game::checkWinner(int x, int y)
{

    // check the actual winner


    QSet<QPoint> winningFields;

    // rows
    map()->getWinnerFromLine(QPoint(x, y), QPoint(1, 0), winLength, &winningFields);

    // columns
    map()->getWinnerFromLine(QPoint(x, y), QPoint(0, 1), winLength, &winningFields);

    // diagonals
    map()->getWinnerFromLine(QPoint(x, y), QPoint(1, 1), winLength, &winningFields);
    map()->getWinnerFromLine(QPoint(x, y), QPoint(1, -1), winLength, &winningFields);

    if(!winningFields.isEmpty()) {
        emit winner(map()->playerAt(*winningFields.begin()), winningFields);
        end();
        return true;
    }

    if(map()->isFull()) {
        emit winner(Player::NoPlayer, winningFields);
        end();
        return true;
    }

    return false;
}

QList<Player*> Game::players() const
{
    return m_players;
}

