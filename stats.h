#include <vector>
#include <limits>
using namespace std;

namespace Statistics {
    class Stats
    {
        public:
            float min,max,avg;
            Stats()
        {
            min = numeric_limits<float>::quiet_NaN();
            max = numeric_limits<float>::quiet_NaN();
            avg = numeric_limits<float>::quiet_NaN();
        }
    };
    Stats ComputeStatistics(const vector<float>& vect);
}

class IAlerter
{
    public:
        virtual void sendAlert() = 0;
};

class EmailAlert:public IAlerter
{
    public:
        bool emailSent;
    EmailAlert():
        emailSent(false)
    {}
    void sendAlert()
    {
        emailSent = true;
    }
};

class LEDAlert:public IAlerter
{
    public:
        bool ledGlows;
    LEDAlert():
        ledGlows(false)
    {}
    void sendAlert()
    {
        ledGlows = true;
    }
};

class StatsAlerter
{
public:
    float maxThreshold;
    vector<IAlerter*> Alerts;
    StatsAlerter(const float maxTh, vector<IAlerter*>alts):
    maxThreshold(maxTh),Alerts(alts)
    {}
    
	void checkAndAlert(const vector<float>& vect)
	{
		auto ComputedStats = Statistics::ComputeStatistics(vect);
		if ( ComputedStats.max > maxThreshold )
		{
			for (int i = 0; i < Alerts.size(); ++i)
			{
				Alerts[i]->sendAlert();
			}
		}
	}      
};
