#ifndef STATS_H
#define STATS_H

class Stats{
    private:
        Stats(){
            nbDeaths = 0;
            nbCollisions = 0;
            nbCreated = 0;
        }

    public:
        int nbDeaths;
        int nbCollisions;
        int nbCreated;

        Stats(Stats &other) = delete;
        void operator=(const Stats &) = delete;

        static Stats& GetInstance() {
            static Stats stats_;
            return stats_;
        }
};

#endif