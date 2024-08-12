#include <iostream.h>

using namespace std;

class Train {
public:
    int arrival, departure;
    Train(int arrival, int departure) {
        this->arrival = arrival;
        this->departure = departure;
    }
};

bool compared(Train* a,Train* b)
{
	return a->departure < b->arrival;
}

int minPlatforms(vector<Train*> &trains) {

	sort(trains.begin(),trains.end(),compared);
	int prevEnd = trains[0]->departure;

	int count = 1;

	for (int i = 1; i < trains.size(); i++)
	{
		if (prevEnd <= trains[i]->arrival)
		{
			count++;
			prevEnd = trains[i]->departure;
		}

	}
	return count;
}

int main()
{
    int N;

    vector<Train*> trains;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
    	int arrival,departure;

    	cin >> arrival >> departure;
    	trains.push_back(new Train(arrival,departure));
    }

    int no_of_trains= minPlatforms(trains);

    cout << no_of_trains;

    return 0;
}
