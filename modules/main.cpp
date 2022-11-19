#include <emails/emails.h>

#include <glog/logging.h>
#include <iostream>
#include <fstream>


int main(){
    FLAGS_logtostderr = 1;
    google::InitGoogleLogging("main log");

    std::ifstream fin("resources/input.txt");

    if(!fin.is_open()) {
        LOG(ERROR) <<  "Cannot open file." << std::endl;
        return 1;
    } LOG(INFO) << "Open file";

    std::ofstream fout("resources/output.txt");
    std::string email;
    while(fin >> email){
        std::string hide_email = emails::hide_email(email);
        LOG(INFO) << "invoke emails::hide_email(\"" << email << "\") and receive \"" << hide_email << "\"";
        fout << hide_email << std::endl;
    } LOG(INFO) << "end of file";

    fin.close();
    fout.close();
}