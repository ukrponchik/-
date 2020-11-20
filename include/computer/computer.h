#pragma once

class Computer {
protected:
    class HardDrive {
    private:
        unsigned int size; // Size of drive in megabytes

    public:
        HardDrive(unsigned int megabytes);

        HardDrive();

        /**
         * Sets the size of drive
         *
         * @param size Size in megabytes
         */
        void setSize(const unsigned int size);

        /// Returns the size of drive in megabytes
        unsigned int getSize() const { return size; };
    } drive;          // Drive of computer

    char *brand;    // Brand of computer
    double price;   // Price of computer
public:
    Computer(unsigned int sizeDrive, const char *brand, double price);

    ~Computer();

    virtual void data() const;
};

struct SIZE {
    unsigned int height, width;

    SIZE(unsigned int height, unsigned int width);
};

class ComputerWithMonitor : protected Computer {
private:
    SIZE monitorSize;

public:
    ComputerWithMonitor(unsigned int sizeDrive, const char *brand, double price, unsigned int height = 450,
                        unsigned int width = 600);

    ~ComputerWithMonitor() = default;

    void data() const override;
};