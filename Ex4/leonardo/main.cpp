#include <iostream>
#include <fourmoment.h>
#include <simulated.h>

using namespace std;

int main()
{
    simulated particle;
    particle.setMoment(0, 1, 1, 1);
    cout << "The pseudorapidity is: " << particle.pseudoRap() << endl;
    cout << "The xy momentum is: " << particle.transverseMomentum('x', 'y') << endl;
    cout << "The yz momentum is: " << particle.transverseMomentum('y', 'z') << endl;

    particle.setID(123);
    particle.setParent(234);

    particle.getInfo();

}
