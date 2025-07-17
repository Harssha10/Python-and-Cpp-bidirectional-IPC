#include "Shm.h"
#include <csignal>
#include <thread>

# define FRAME_SIZE 4092
# define MUTEX_SIZE 40
# define TOTAL_SIZE FRAME_SIZE+MUTEX_SIZE

bool RUN_THREADS=true;
Shm* get_data;
Shm* send_data;
void handle_sigint(int sig) {
    RUN_THREADS=false;
    delete send_data;
    delete get_data;
    exit(0);
}
void get_data_loop(Shm* get_data){
    std::string previous;
    bool python_terminated=false;
    while(RUN_THREADS){
        std::string testing=get_data->read();
        if(testing!=previous)std::cout<<testing<<std::endl;
        previous=testing;
        if(testing=="terminate"){
            RUN_THREADS=false;
            python_terminated=true;
        }
    }
    printf("exiting get_data_loop..\n");
    if(python_terminated)printf("=====ENTER ANY KEY TO STOP=====\n");
}

void send_data_loop(Shm* send_data){
    std::string text;
    while (RUN_THREADS) {
        std::getline(std::cin, text);
        send_data->write(text);
        if(text=="terminate")RUN_THREADS=false;
    }
    printf("exiting send_data_loop..\n");
}

int main() {
    signal(SIGINT, handle_sigint);
    try{
        send_data= new Shm("send_data", TOTAL_SIZE, true);
        get_data= new Shm("get_data", TOTAL_SIZE, true);
    }
    catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::thread handle_get_data(get_data_loop,get_data);
    std::thread handle_send_data(send_data_loop,send_data);
    handle_get_data.join();
    handle_send_data.join();
    sleep(1);
    delete send_data,get_data;
    return 0;
}