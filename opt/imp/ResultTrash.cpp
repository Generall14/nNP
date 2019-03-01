#include "ResultTrash.hpp"

ResultKeeperTrash::ResultKeeperTrash()
{
    _res.push_back(res{std::vector<float>(), "", 0.0});
}

void ResultKeeperTrash::append(std::vector<float>, float, std::string)
{

}

std::string ResultKeeperTrash::report() const
{
    return "";
}
