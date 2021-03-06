#ifndef TESTS_H
#define TESTS_H

#include <bitset>
#include <chrono>
#include <ctime>
#include <fstream>
#include <future>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

#include <web3cpp/Web3.h>
#include <web3cpp/Contract.h>
#include <web3cpp/Solidity.h>
#include <web3cpp/Utils.h>

// Helper class for unit testing.

class Tests {
  private:
    // Password for the wallet and log stream object for writing test processes
    std::string password;
    std::ofstream logStream;

    // Log file and test wallet folder
    std::string logFile = "web3cpp-test-log.txt";
    boost::filesystem::path walletFolder = "web3cpp-test-wallet";

    // Counters for passed/failed tests, error reason (if any),
    // and functions for controlling those
    int pass = 0;
    int fail = 0;
    bool curPass;
    std::string curReason;
    void passed() { curPass = true; curReason = ""; pass++; }
    void failed(std::string msg) { curPass = false; curReason = msg; fail++; }

  public:
    // The Web3 object that will be tested
    Web3* web3 = NULL;

    // Constructor
    Tests(std::string &password) {
      std::cout << "Creating/Loading wallet... " << std::flush;
      web3 = new Web3(new Provider("avax-c-test"), &walletFolder);
      Error error;
      if (!web3->wallet.loadWallet(password, error)) {
        std::cout << std::string("Could not load wallet: ") << error.what() << std::endl;
        throw;
      }
      this->password = password;
      logStream.open(logFile, std::ofstream::out | std::ofstream::app);
      std::time_t t = std::time(nullptr);
      std::tm* tm = std::localtime(&t);
      std::stringstream timestream;
      timestream << std::put_time(tm, "%d-%m-%Y %H-%M-%S");
      logStream << "[web3cpp Test Log - " << timestream.str() << "]\n\n";
      std::cout << "Ready!" << std::endl;
      std::cout << "Using provider: " << web3->getProvider()->getName() << std::endl;
      std::cout << "Starting tests..." << std::endl;
    }

    // Destructor
    ~Tests() { logStream.close(); delete web3; }

    // Show overall test results
    void showResults() {
      std::cout <<
        "* RESULTS: " << pass << " passed, " << fail << " failed" << std::endl
        << "* Check the log file " << logFile << " for details"
      << std::endl;
    }

    /**
     * Tests start here, divided by class.
     * Each test should be completely contained into a function of its own
     * and output the details to the log file.
     */

    // ==============================================================
    // BIP39
    // ==============================================================

    // Test for generating a new mnemonic.
    void testMnemonicGeneration();

    // Test for generating a key pair based on a mnemonic and derivation path.
    void testKeyPairGeneration();

    // Test for checking valid words for mnemonics.
    void testMnemonicWordValidity();

    // Test for generating addresses from a given seed, derivation path and index.
    void testMnemonicAddressGeneration();

    // ==============================================================
    // DATABASE
    // ==============================================================

    // Test for all Database operations at once.
    void testDatabaseCRUD();

    // ==============================================================
    // NET
    // ==============================================================

    // Tests for normal and custom HTTP requests, respectively.
    void testHTTPRequest();
    void testCustomHTTPRequest();

    // ==============================================================
    // CIPHER
    // ==============================================================

    // Tests for encrypting and decrypting data (normal and legacy).
    void testCipherNormal();
    void testCipherLegacy();

    // ==============================================================
    // SOLIDITY
    // ==============================================================

    // Test for checking the validity of each supported type.
    void testTypeChecks();

    // Tests for packing each supported type individually.
    void testFunction();
    void testUint();
    void testAddress();
    void testBool();
    void testBytes();
    void testString();
    void testUintArray();
    void testAddressArray();
    void testBoolArray();
    void testBytesArray();
    void testStringArray();

    // Test for encoding a complete ABI.
    void testMulti();

    // ==============================================================
    // UTILS
    // ==============================================================

    // Test for random hex string generation at preset sizes.
    void testRandomHexes();

    // Test for parsing of large numbers as BigNumbers.
    void testBigNumbers();

    // Test for SHA3 hashing (normal and raw).
    void testSHA3();

    // Test for Solidity SHA3 hashing (normal only).
    void testSoliditySHA3();

    // Test for Solidity SHA3 hashing (raw only).
    void testSoliditySHA3Raw();

    // Test for hex string detection.
    void testHexes();

    // Test for address detection.
    void testAddresses();

    // Test for address conversions (upper, lower and checksum).
    void testAddressConversions();

    // Test for address checksums.
    void testAddressChecksums();

    // Test for hex data conversions (number, number string and text string).
    void testHexConversions();

    // Test for hex prefix stripping.
    void testHexStripping();

    // Test for type conversions, from HEX to something.
    void testFromHexToTypes();

    // Test for type conversions, from something to HEX.
    void testFromTypesToHex();

    // Test for currency conversions, from Wei to fixed point and vice-versa.
    void testWeiConversions();

    // Test for HEX string padding (left and right).
    void testHexPadding();

    // ==============================================================
    // WALLET
    // ==============================================================

    /**
     * Test for valid Account generation.
     * Created test Account is automatically deleted at the end of the test.
     */
    void generateAccount();

    // Tests for password check and storage/clearing, respectively.
    void handlePasswordCheck();
    void handlePasswordStorageAuto();
    void handlePasswordStorageManual();

    /**
     * Test for signing and recovering a signed message.
     * Require at least ONE existing Account, which is created automatically
     * if it doesn't exist. Test WILL fail if this part fails too.
     */
    void signAndRecoverMessage();

    /**
     * Test for building, signing, sending and storing a transaction in history.
     * Require at least ONE existing Account WITH FUNDS.
     * Account will NOT be automatically created and funds can NOT be
     * automatically fetched.
     * Make sure you go to a faucet and get AT LEAST 0.01 AVAX
     * before running the test, otherwise it'll automatically fail.
     */
    void testTransaction();

    // ==============================================================
    // CONTRACT
    // ==============================================================

    // Test for proper Contract loading and ABI manipulation.
    // "Legacy" tests the older method, "Normal" tests the newer one.
    // Check Contract.h for more details.
    void loadAndTestContractLegacy();
    void loadAndTestContractNormal();
};

#endif // TESTS_H
