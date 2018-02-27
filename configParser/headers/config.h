typedef unsigned int uint;

struct config
{

public:

    config(){
        this->offset = -1;
        this->block_length = -1;
        this->type_crc = -1;
        this->payload = "";
    }

    uint offset;
    uint block_length;
    uint type_crc;
    std::string payload;
};
