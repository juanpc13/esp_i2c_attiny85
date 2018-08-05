struct Attiny85_Data {
  uint16_t analog;
  uint16_t input1;
  uint16_t input2;  
};

class Attiny85_I2c_Slave {
  private:
    uint8_t address;

    uint16_t resquest(uint8_t address_request){
      uint16_t data = 0;
      Wire.beginTransmission(address);
      Wire.write(address_request);
      Wire.requestFrom(13, 2);
      data = Wire.read() << 2 | Wire.read();
      Wire.endTransmission();
      return data;
    }

  public:
    Attiny85_I2c_Slave(uint8_t _address) {
      address = _address;
    }

    bool begin() {
      Wire.begin(0, 2);
      return resquest(0) == address;
    }

    Attiny85_Data getData(){
      Attiny85_Data info = {resquest(1), resquest(3), resquest(4)};      
      return info;
    }

};
