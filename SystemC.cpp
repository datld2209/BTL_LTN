#include <systemc.h>

SC_MODULE(Sensor) {
    sc_in<bool> clk;
    sc_out<bool> detected;

    SC_CTOR(Sensor) {
        SC_THREAD(detect);
        sensitive << clk.pos();
    }

    void detect() {
        while (true) {
            // Simulate sensor detection logic
            bool isDetected = (rand() % 2) == 1;  // 50% chance of detecting 1

            // Send detection signal
            detected.write(isDetected);

            wait();
        }
    }
};

SC_MODULE(Controller) {
    sc_in<bool> detected[5];
    sc_out<bool> steering;

    SC_CTOR(Controller) {
        SC_METHOD(control);
        sensitive << detected[0] << detected[1] << detected[2] << detected[3] << detected[4];
    }

    void control() {
        bool sensor1 = detected[0].read();
        bool sensor2 = detected[1].read();
        bool sensor3 = detected[2].read();
        bool sensor4 = detected[3].read();
        bool sensor5 = detected[4].read();

        if (sensor1 == 0) {
            // Turn right
            steering.write(false);
        } else if (sensor5 == 0) {
            // Turn left
            steering.write(true);
        } else if (sensor1 == 1 && sensor2 == 1 && sensor3 == 1 && sensor4 == 1 && sensor5 == 1) {
            // Go straight if all sensors detect 1
            steering.write(true);
        } else {
            // Default: Go straight
            steering.write(true);
        }
    }
};

SC_MODULE(Car) {
    sc_in<bool> steering;
    sc_in<bool> clk;

    SC_CTOR(Car) {
        SC_THREAD(drive);
        sensitive << clk.pos();
    }

    void drive() {
        while (true) {
            // Simulate car movement
            if (steering.read()) {
                cout << "[Car] Moving straight." << endl;
            } else {
                cout << "[Car] Adjusting direction." << endl;
            }

            wait();
        }
    }
};

int sc_main(int argc, char* argv[]) {
    // Create signals
    sc_clock clk("clk", 10, SC_NS);
    sc_signal<bool> detected[5];
    sc_signal<bool> steering;

    // Create modules
    Sensor sensor[5]{"sensor1", "sensor2", "sensor3", "sensor4", "sensor5"};
    Controller controller("controller");
    Car car("car");

    // Connect signals
    for (int i = 0; i < 5; i++) {
        sensor[i].clk(clk);
        sensor[i].detected(detected[i]);
        controller.detected[i](detected[i]);
    }
    controller.steering(steering);
    car.steering(steering);
    car.clk(clk);

    // Start simulation
    sc_start(100, SC_NS);

    return 0;
}