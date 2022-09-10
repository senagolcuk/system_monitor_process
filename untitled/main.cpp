#include <thread>
#include <boost/process.hpp>

int main() {
    namespace bp = boost::process;
    bp::group g; // create a group object
    bp::child c(
            bp::search_path("bash"),
            std::vector<std::string>{
                    "-c", "/home/sena/Files/ISUZU_scripts/system-monitor.sh"},
            g); // create child class for system_monitor
    std::this_thread::sleep_for(std::chrono::seconds(10));

    bp::system (bp::search_path("bash"),
                std::vector<std::string>{
                         "-c", "/home/sena/Files/ISUZU_scripts/kill_process.sh"}); // create system class for kill process and kill reader
    g.terminate(); // kill child process
    c.wait();
    return 0;
}
