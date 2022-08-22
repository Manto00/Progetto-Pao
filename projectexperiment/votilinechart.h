#ifndef VOTIPOINTCHART_H
#define VOTIPOINTCHART_H

#include <vector>
#include <usermodel.h>

class votiLineChart
{
private:
    std::vector<unsigned int*> voti;
    unsigned int punteggioMassimo;
public:
    votiLineChart(usermodel*m);
};

#endif // VOTIPOINTCHART_H
