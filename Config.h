#ifndef CONFIG_H
#define CONFIG_H
#include <iostream>

class Config {
    private:
        Config(int width,int height,double minSize,double maxSize, double minSpeed, double maxSpeed,
            int ageMin,int ageMax, double gregariousRate,double fearfulRate,double kamikazeRate,
            double farsightedRate, double multiplePersonnalityRate, double birthRate, double deathRateMax,
            double cloneRateMax,double fieldViewMin, double fieldViewMax, double detectionRateMin,
            double detectionRateMax,double detectionDistanceMin, double detectionDistanceMax,
            double eyesRate, double earsRate,double speedFactorMin, double speedFactorMax, double resistanceFactorMin, double resistanceFactorMax,
            double slowFactorMin, double slowFactorMax, double camouflageFactorMin, double camouflageFactorMax,
            double scaredSpeedMax, double scaredThresholdMax, double switchRateMax) :
                width(width),height(height),minSize(minSize),maxSize(maxSize), minSpeed(minSpeed),
                maxSpeed(maxSpeed),ageMin(ageMin),ageMax(ageMax),
                birthRate(birthRate),deathRateMax(deathRateMax),cloneRateMax(cloneRateMax),
                fieldViewMin(fieldViewMin),fieldViewMax(fieldViewMax),detectionRateMin(detectionRateMin),
                detectionRateMax(detectionRateMax),detectionDistanceMin(detectionDistanceMin),
                detectionDistanceMax(detectionDistanceMax),eyesRate(eyesRate),earsRate(earsRate),speedFactorMin(speedFactorMin),
                speedFactorMax(speedFactorMax),resistanceFactorMin(resistanceFactorMin),resistanceFactorMax(resistanceFactorMax),slowFactorMin(slowFactorMin),
                slowFactorMax(slowFactorMax),camouflageFactorMin(camouflageFactorMin),
                camouflageFactorMax(camouflageFactorMax),scaredSpeedMax(scaredSpeedMax),
                scaredThresholdMax(scaredThresholdMax),switchRateMax(switchRateMax){
                    if (gregariousRate+fearfulRate+kamikazeRate+farsightedRate +
                        multiplePersonnalityRate != 1){
                            std::cout<<"Wrong reparition, going to use uniform repartition for behavior"<<std::endl;
                            repartition[0] = 0.2;
                            repartition[1] = 0.2;
                            repartition[2] = 0.2;
                            repartition[3] = 0.2;
                            repartition[4] = 0.2;
                    } else {
                        repartition[0] = gregariousRate;
                        repartition[1] = fearfulRate;
                        repartition[2] = kamikazeRate;
                        repartition[3] = farsightedRate;
                        repartition[4] = multiplePersonnalityRate;
                    }
        }

        Config() {
            width = 640;
            height = 480;
            minSize = 3;
            maxSize = 15;
            minSpeed = 1;
            maxSpeed = 10;
            ageMin = 100;
            ageMax = 400;
            repartition[0] = 0.2; //gregariousRate
            repartition[1] = 0.2; //fearfulRate
            repartition[2] = 0.2; //kamikazeRate
            repartition[3] = 0.2; //farsightedRate
            repartition[4] = 0.2; //multiplePersonnalityRate
            birthRate = 0.01;
            deathRateMax = 0.5;
            cloneRateMax = 0.01;
            fieldViewMin = M_PI/8;
            fieldViewMax = M_PI/2;
            detectionRateMin = 0.3;
            detectionRateMax = 1;
            detectionDistanceMin = 20;
            detectionDistanceMax = 100;
            eyesRate = 0.5;
            earsRate = 0.5;
            speedFactorMin = 1.2;
            speedFactorMax = 2;
            resistanceFactorMin = 1.5;
            resistanceFactorMax = 3;
            slowFactorMin = 3;
            slowFactorMax = 8;
            camouflageFactorMin = 0.6;
            camouflageFactorMax = 1,
            scaredSpeedMax = 5;
            scaredThresholdMax = 5;
            switchRateMax = 0.1;
        }

    public:
        int width,height;
        double minSize,maxSize;
        double minSpeed,maxSpeed;
        int ageMin, ageMax;
        double repartition[5]; //Elements sum = 1
        double birthRate;
        double deathRateMax,cloneRateMax;
        double fieldViewMin, fieldViewMax;
        double detectionRateMin, detectionRateMax;
        double detectionDistanceMin, detectionDistanceMax;
        double eyesRate,earsRate;
        double speedFactorMin, speedFactorMax, resistanceFactorMin, resistanceFactorMax;
        double slowFactorMin, slowFactorMax;
        double camouflageFactorMin, camouflageFactorMax;
        double scaredSpeedMax, scaredThresholdMax;
        double switchRateMax;

        Config(Config &other) = delete;
        void operator=(const Config &) = delete;

        static Config& GetInstance() {
            static Config config_;
            return config_;
        }
};

#endif
