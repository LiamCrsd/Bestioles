#ifndef CONFIG_H
#define CONFIG_H

struct Config{
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
    Config getConfig();
    private:
        Config();
};
#endif