class Logger 
{
public:
    unordered_map<string, int> log;
    bool shouldPrintMessage(int timestamp, string message) 
    {
        if (log.count(message) && (timestamp - log[message] < 10))
            return false;
        log[message] = timestamp;
        return true;
    }
};


/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */