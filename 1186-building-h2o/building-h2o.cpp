class H2O 
{
    int hydrogenCount = 0;  // Number of hydrogens ready
    int oxygenCount = 0;    // Number of oxygens ready

    mutex mtx;
    condition_variable cv;

public:
    H2O() 
    {
        
    }
    void hydrogen(std::function<void()> releaseHydrogen) 
    {
        unique_lock<std::mutex> lock(mtx);

        // Wait until less than 2 hydrogens are present
        cv.wait(lock, [this] { return hydrogenCount < 2; });

        hydrogenCount++;
    
        if (hydrogenCount == 2 && oxygenCount == 1) 
        {
            // Reset for next molecule
            hydrogenCount = 0;
            oxygenCount = 0;
            cv.notify_all();
        }
         releaseHydrogen();  // Bond immediately
    }

    void oxygen(std::function<void()> releaseOxygen) 
    {
        unique_lock<std::mutex> lock(mtx);

        // Wait until no oxygen is present
        cv.wait(lock, [this] { return oxygenCount < 1; });

        oxygenCount++;
      
        if (hydrogenCount == 2 && oxygenCount == 1)
        {
            // Reset for next molecule
            hydrogenCount = 0;
            oxygenCount = 0;

            cv.notify_all();
        }
        releaseOxygen();  // Bond immediately
    }
};