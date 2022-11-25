#ifndef CONFIG_H
#define CONFIG_H
#include <iostream>
struct Config{
    static Config* config;

    int width,heigth;
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
    double speedFactorMax, resistanceFactorMax, slowFactorMax;
    double camouflageFactorMin, camouflageFactorMax;
    double scaredSpeedMax, scaredThresholdMax;
    double switchRateMax;

    Config(Config &other) = delete;
    void operator=(const Config&) = delete;

    Config* Config::instance = nullptr;

    Config* getConfig(int width,int height,double minSize, double maxSize, double minSpeed, double maxSpeed,
            int ageMin,int ageMax, double gregariousRate,double fearfulRate,double kamikazeRate,
            double farsightedRate, double multiplePersonnalityRate, double birthRate, double deathRateMax,
            double cloneRateMax,double fieldViewMin, double fieldViewMax, double detectionRateMin,
            double detectionRateMax,double detectionDistanceMin, double detectionDistanceMax,
            double eyesRate, double earsRate, double speedFactorMax, double resistanceFactorMax,
            double slowFactorMax, double camouflageFactorMin, double camouflageFactorMax,
            double scaredSpeedMax, double scaredThresholdMax, double switchRateMax){
                if (instance == nullptr){
                    config = new Config(width,height,minSize,maxSize,minSpeed,maxSpeed,
               ageMin,ageMax,gregariousRate,fearfulRate,kamikazeRate,
               farsightedRate,multiplePersonnalityRate,birthRate,deathRateMax,
               cloneRateMax,fieldViewMin,fieldViewMax,detectionRateMin,
               detectionRateMax,detectionDistanceMin,detectionDistanceMax,
               eyesRate,earsRate,speedFactorMax,resistanceFactorMax,
               slowFactorMax,camouflageFactorMin,camouflageFactorMax,
               scaredSpeedMax,scaredThresholdMax,switchRateMax);
               }
               return config;
            };
    
    private:
        Config(int width,int height,double minSize,double maxSize, double minSpeed, double maxSpeed,
            int ageMin,int ageMax, double gregariousRate,double fearfulRate,double kamikazeRate,
            double farsightedRate, double multiplePersonnalityRate, double birthRate, double deathRateMax,
            double cloneRateMax,double fieldViewMin, double fieldViewMax, double detectionRateMin,
            double detectionRateMax,double detectionDistanceMin, double detectionDistanceMax,
            double eyesRate, double earsRate, double speedFactorMax, double resistanceFactorMax,
            double slowFactorMax, double camouflageFactorMin, double camouflageFactorMax,
            double scaredSpeedMax, double scaredThresholdMax, double switchRateMax) : 
                width(width),heigth(heigth),minSize(minSize),maxSize(maxSize), minSpeed(minSpeed),
                maxSpeed(maxSpeed),ageMin(ageMin),ageMax(ageMax),
                birthRate(birthRate),deathRateMax(deathRateMax),cloneRateMax(cloneRateMax),
                fieldViewMin(fieldViewMin),fieldViewMax(fieldViewMax),detectionRateMin(detectionRateMin),
                detectionRateMax(detectionRateMax),detectionDistanceMin(detectionDistanceMin),
                detectionDistanceMax(detectionDistanceMax),eyesRate(eyesRate),earsRate(earsRate),
                speedFactorMax(speedFactorMax),resistanceFactorMax(resistanceFactorMax),
                slowFactorMax(slowFactorMax),camouflageFactorMin(camouflageFactorMin),
                camouflageFactorMax(camouflageFactorMax),scaredSpeedMax(scaredSpeedMax),
                scaredThresholdMax(scaredThresholdMax),switchRateMax(switchRateMax){
                    if (gregariousRate+fearfulRate+kamikazeRate+farsightedRate +
                        multiplePersonnalityRate != 1){
                            std::cout<<"Wrong reparition, going to use uniform repartition for behavior"<<std::endl;
                            gregariousRate = 0.2;
                            fearfulRate = 0.2;
                            kamikazeRate = 0.2;
                            farsightedRate = 0.2;
                            multiplePersonnalityRate = 0.2;

                        }
                    repartition[0] = gregariousRate;
                    repartition[1] = fearfulRate;
                    repartition[2] = kamikazeRate;
                    repartition[3] = farsightedRate;
                    repartition[4] = multiplePersonnalityRate;
                }
};
#endif