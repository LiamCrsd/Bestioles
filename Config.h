#ifndef CONFIG_H
#define CONFIG_H
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

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
                        multiplePersonnalityRate > 1){
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
            std::ifstream fichier("./config.txt");
            if(fichier)
            {
              std::string ligne;
              getline(fichier,ligne);
              width = stoi(ligne.substr(14));
              getline(fichier,ligne);
              height = stoi(ligne.substr(15));
              getline(fichier,ligne);
              minSize = stod(ligne.substr(10));
              getline(fichier,ligne);
              maxSize = stod(ligne.substr(10));
              getline(fichier,ligne);
              minSpeed = stod(ligne.substr(11));
              getline(fichier,ligne);
              maxSpeed = stod(ligne.substr(11));
              getline(fichier,ligne);
              ageMin = stoi(ligne.substr(15));
              getline(fichier,ligne);
              ageMax = stoi(ligne.substr(15));
              getline(fichier,ligne);
              repartition[0] = stod(ligne.substr(17)); //gregariousRate
              getline(fichier,ligne);
              repartition[1] = stod(ligne.substr(14)); //fearfulRate
              getline(fichier,ligne);
              repartition[2] = stod(ligne.substr(15)); //kamikazeRate
              getline(fichier,ligne);
              repartition[3] = stod(ligne.substr(17)); //farsightedRate
              getline(fichier,ligne);
              repartition[4] = stod(ligne.substr(27)); //multiplePersonnalityRate
              getline(fichier,ligne);
              birthRate = stod(ligne.substr(12));
              getline(fichier,ligne);
              deathRateMax = stod(ligne.substr(15));
              getline(fichier,ligne);
              cloneRateMax = stod(ligne.substr(15));
              getline(fichier,ligne);
              fieldViewMin = M_PI/stod(ligne.substr(22));
              getline(fichier,ligne);
              fieldViewMax = M_PI/stod(ligne.substr(22));
              getline(fichier,ligne);
              detectionRateMin = stod(ligne.substr(19));
              getline(fichier,ligne);
              detectionRateMax = stod(ligne.substr(19));
              getline(fichier,ligne);
              detectionDistanceMin = stod(ligne.substr(23));
              getline(fichier,ligne);
              detectionDistanceMax = stod(ligne.substr(23));
              getline(fichier,ligne);
              eyesRate = stod(ligne.substr(11));
              getline(fichier,ligne);
              earsRate = stod(ligne.substr(11));
              getline(fichier,ligne);
              speedFactorMin = stod(ligne.substr(17));
              getline(fichier,ligne);
              speedFactorMax = stod(ligne.substr(17));
              getline(fichier,ligne);
              resistanceFactorMin = stod(ligne.substr(22));
              getline(fichier,ligne);
              resistanceFactorMax = stod(ligne.substr(22));
              getline(fichier,ligne);
              slowFactorMin = stod(ligne.substr(16));
              getline(fichier,ligne);
              slowFactorMax = stod(ligne.substr(16));
              getline(fichier,ligne);
              camouflageFactorMin = stod(ligne.substr(22));
              getline(fichier,ligne);
              camouflageFactorMax = stod(ligne.substr(22));
              getline(fichier,ligne);
              scaredSpeedMax = stod(ligne.substr(17));
              getline(fichier,ligne);
              scaredThresholdMax = stod(ligne.substr(21));
              getline(fichier,ligne);
              switchRateMax = stod(ligne.substr(16));
            }
            else
            {
              std::cout << "error txt" << std::endl;
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
        double scaredSpeedMax;
        int scaredThresholdMax;
        double switchRateMax;

        Config(Config &other) = delete;
        void operator=(const Config &) = delete;

        static Config& GetInstance() {
            static Config config_;
            return config_;
        }
};

#endif
