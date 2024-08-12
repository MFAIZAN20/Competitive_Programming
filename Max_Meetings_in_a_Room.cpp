#include <iostream.h>

using namespace std;

class Meeting {
public:
    int start, end;
    Meeting(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

bool compared(Meeting* a,Meeting* b)
{
	return a->end < b->end;
}

int getMaxMeetings(vector<Meeting*> &meetings) {
	
	sort(meetings.begin(),meetings.end(), compared);

	int count = 1;
	int prevEnd = meetings[0]->start;
    for (int i = 1; i < meetings.size(); i++)
    {
    	if (meetings[i]->start >= prevEnd)
    	{
    		count++;
    		prevEnd = meetings[i]->end;
		}
    }
    return count;
}


int main()
{
    int N, Sum = 0;

    vector<Meeting*> meetings;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
    	int start,end;

    	cin >>start >>end;
    	 meetings.push_back(new Meeting(start, end)); 
    }

    int time = getMaxMeetings(meetings);

    cout << time;

    return 0;
}
