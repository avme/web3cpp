#include "Tests.h"

void Tests::loadAndTestContractLegacy() {
  std::cout << "* Running test: " << __func__ << "... " << std::flush;
  Error error;
  std::string const addToAddressListExpected = "0x5fd673e8000000000000000000000000000000000000000000000000000000000000002000000000000000000000000000000000000000000000000000000000000000020000000000000000000000002e913a79206280b3882860b3ef4df8204a62c8b10000000000000000000000002e913a79206280b3882860b3ef4df8204a62c8b1";
  std::string const addToStringListExpected = "0xece4955100000000000000000000000000000000000000000000000000000000000000200000000000000000000000000000000000000000000000000000000000000002000000000000000000000000000000000000000000000000000000000000004000000000000000000000000000000000000000000000000000000000000000c00000000000000000000000000000000000000000000000000000000000000052616161616161616161616161616161616161616161616161616161616161616161616161616161616161616161616161616161616161616161616161616161616161616161616161616161616161616161610000000000000000000000000000000000000000000000000000000000000000000000000000000000000000004f626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262620000000000000000000000000000000000";
  std::string const addToStringListFourExpected = "0xece4955100000000000000000000000000000000000000000000000000000000000000200000000000000000000000000000000000000000000000000000000000000004000000000000000000000000000000000000000000000000000000000000008000000000000000000000000000000000000000000000000000000000000000e0000000000000000000000000000000000000000000000000000000000000016000000000000000000000000000000000000000000000000000000000000001c0000000000000000000000000000000000000000000000000000000000000002461616161616161616161616161616161616161616161616161616161616161616161616100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000005862626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262000000000000000000000000000000000000000000000000000000000000000000000000000000286363636363636363636363636363636363636363636363636363636363636363636363636363636300000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000046464646400000000000000000000000000000000000000000000000000000000";
  std::string const addToBytesListExpected = "0x8ab94fd600000000000000000000000000000000000000000000000000000000000000200000000000000000000000000000000000000000000000000000000000000002000000000000000000000000000000000000000000000000000000000000004000000000000000000000000000000000000000000000000000000000000000800000000000000000000000000000000000000000000000000000000000000002aaaa0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002bbbb000000000000000000000000000000000000000000000000000000000000";
  std::string const addToBytesListFourExpected = "0x8ab94fd600000000000000000000000000000000000000000000000000000000000000200000000000000000000000000000000000000000000000000000000000000004000000000000000000000000000000000000000000000000000000000000008000000000000000000000000000000000000000000000000000000000000000c00000000000000000000000000000000000000000000000000000000000000100000000000000000000000000000000000000000000000000000000000000014000000000000000000000000000000000000000000000000000000000000000090aaaaaaaaaaaaaaaaa0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001fbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb0000000000000000000000000000000000000000000000000000000000000000020ccc00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000120ddddddddddddddddddddddddddddddddddd0000000000000000000000000000";
  std::string const testMultipleByteArrayExpected = "0x70afa559000000000000000000000000000000000000000000000000000000000000004000000000000000000000000000000000000000000000000000000000000001200000000000000000000000000000000000000000000000000000000000000002000000000000000000000000000000000000000000000000000000000000004000000000000000000000000000000000000000000000000000000000000000800000000000000000000000000000000000000000000000000000000000000002aaaa0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002bbbb0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002000000000000000000000000000000000000000000000000000000000000004000000000000000000000000000000000000000000000000000000000000000800000000000000000000000000000000000000000000000000000000000000002cccc0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002dddd000000000000000000000000000000000000000000000000000000000000";
  std::string const addMultipleToByteListExpected = "0xf953151e000000000000000000000000000000000000000000000000000000000000004000000000000000000000000000000000000000000000000000000000000000c00000000000000000000000000000000000000000000000000000000000000046aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002bbbb000000000000000000000000000000000000000000000000000000000000";
  std::string const addMultipleToStringListExpected = "0x4aee7a8d000000000000000000000000000000000000000000000000000000000000004000000000000000000000000000000000000000000000000000000000000000800000000000000000000000000000000000000000000000000000000000000003616161000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000036262620000000000000000000000000000000000000000000000000000000000";
  std::string const testAlmostAllExpected = "0x1608f4b100000000000000000000000000000000000000000000000000007614cf69b633000000000000000000000000c4ea73d428ab6589c36905d0f0b01f3051740ff800000000000000000000000000000000000000000000000000000000000000010000000000000000000000000000000000000000000000000000000000000100000000000000000000000000000000000000000000000000000000000000014000000000000000000000000000000000000000000000000000000000000002e0000000000000000000000000000000000000000000000000000000000000046000000000000000000000000000000000000000000000000000000000000004e00000000000000000000000000000000000000000000000000000000000000002aaaa000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000016d4c6f72656d20697073756d20646f6c6f722073697420616d65742c20636f6e73656374657475722061646970697363696e6720656c69742e2050656c6c656e746573717565206567657420706f72747469746f7220746f72746f722c2065742074696e636964756e74206e6962682e2041656e65616e2065726174207175616d2c206d6178696d757320696420677261766964612073697420616d65742c2072686f6e63757320736564206e756c6c612e20437572616269747572206d6178696d75732074656c6c7573206469616d2c2076656c2076756c7075746174652073617069656e206d6178696d75732076697461652e204475697320636f6e73656374657475722c2066656c69732061742065666669636974757220636f6e73656374657475722c20746f72746f72206e69736c20626962656e64756d206d61757269732c20656765742076656e656e61746973206175677565206a7573746f206574206f72636953696d706c6520000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000003000000000000000000000000000000000000000000000000000000000000006000000000000000000000000000000000000000000000000000000000000000a00000000000000000000000000000000000000000000000000000000000000120000000000000000000000000000000000000000000000000000000000000000561616161610000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000054626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262000000000000000000000000000000000000000000000000000000000000000000000000000000000000000363636300000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000003000000000000000000000000c4ea73d428ab6589c36905d0f0b01f3051740ff8000000000000000000000000c4ea73d428ab6589c36905d0f0b01f3051740ff8000000000000000000000000c4ea73d428ab6589c36905d0f0b01f3051740ff80000000000000000000000000000000000000000000000000000000000000003000000000000000000000000000000000000000000000000000000000000006000000000000000000000000000000000000000000000000000000000000000a000000000000000000000000000000000000000000000000000000000000000e000000000000000000000000000000000000000000000000000000000000000020aaa00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000020bbb0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000021aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa00000000000000000000000000000000000000000000000000000000000000";

  boost::filesystem::path contractPath(
    boost::filesystem::current_path().parent_path().string()
    + "/tests/ArrayTest.json"
  );
  json contractJson = Utils::readJSONFile(contractPath);
  Contract ArrayTest(contractJson, "0x0000000000000000000000000000000000000000");
  std::string addToAddressList = ArrayTest("addToAddressListArr",
    json::array({
      json::array({
        "0x2E913a79206280B3882860B3eF4dF8204a62C8B1",
        "0x2E913a79206280B3882860B3eF4dF8204a62C8B1"
      })
    })
  , error);

  std::string addToStringList = ArrayTest("addToStringListArr",
    json::array({
      json::array({
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
        "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"
      })
    })
  , error);

  std::string addToStringListFour = ArrayTest("addToStringListArr",
    json::array({
      json::array({
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
        "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
        "cccccccccccccccccccccccccccccccccccccccc",
        "dddd"
      })
    })
  , error);

  std::string addToBytesList = ArrayTest("addToByteListArr",
    json::array({
      json::array({
        "0xaaaa",
        "0xbbbb"
      })
    })
  , error);

  std::string addToBytesListFour = ArrayTest("addToByteListArr",
    json::array({
      json::array({
        "0xaaaaaaaaaaaaaaaaa",
        "0xbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
        "0xccc",
        "0xddddddddddddddddddddddddddddddddddd"
      })
    })
  , error);

  std::string testMultipleByteArray = ArrayTest("testMultipleByteArray",
    json::array({
      json::array({
        "0xaaaa",
        "0xbbbb"
      }),
      json::array({
        "0xcccc",
        "0xdddd"
      })
    })
  , error);

  std::string addMultipleToByteList = ArrayTest("addMultipleToByteList",
    json::array({
      "0xaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
      "0xbbbb"
    })
  , error);

  std::string addMultipleToStringList = ArrayTest("addMultipleToStringList",
    json::array({
      "aaa",
      "bbb"
    })
  , error);

  // This should do it lmao.
  // testAlmostAll(uint256 item1, address item2, bool item3, bytes item4, string item5, string[] item6, address[] item7, bytes[] item8)
  std::string testAlmostAll = ArrayTest("testAlmostAll",
    json::array({
      "129831751235123",
      "0xc4ea73d428ab6589c36905d0f0b01f3051740ff8",
      "1",
      "0xaaaa",
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Pellentesque eget porttitor tortor, et tincidunt nibh. Aenean erat quam, maximus id gravida sit amet, rhoncus sed nulla. Curabitur maximus tellus diam, vel vulputate sapien maximus vitae. Duis consectetur, felis at efficitur consectetur, tortor nisl bibendum mauris, eget venenatis augue justo et orciSimple ",
      json::array({
        "aaaaa",
        "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
        "ccc"
      }),
      json::array({
        "0xc4ea73d428ab6589c36905d0f0b01f3051740ff8",
        "0xc4ea73d428ab6589c36905d0f0b01f3051740ff8",
        "0xc4ea73d428ab6589c36905d0f0b01f3051740ff8"
      }),
      json::array({
        "0xaaa",
        "0xbbb",
        "0xaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      })
    })
    , error);

  if (error.getCode() != 0) {
    failed(error.what());
  } else if (addToAddressList != addToAddressListExpected) {
    failed("ABI doesn't match function: addToAddressListArr(address[]) two items");
  } else if (addToStringList != addToStringListExpected) {
    failed("ABI doesn't match function: addToStringListArr(string[]) two items");
  } else if (addToStringListFour != addToStringListFourExpected) {
    failed("ABI doesn't match function: addToStringListArr(string[]) four items");
  } else if (addToBytesList != addToBytesListExpected) {
    failed("ABI doesn't match function: addToByteListArr(bytes[]) two items");
  } else if (addToBytesListFour != addToBytesListFourExpected) {
    failed("ABI doesn't match function: addToByteListArr(bytes[]) four items");
  } else if (testMultipleByteArray != testMultipleByteArrayExpected) {
    failed("ABI doesn't match function: testMultipleByteArray(bytes[],bytes[])");
  } else if (addMultipleToByteList != addMultipleToByteListExpected) {
    failed("ABI doesn't match function: addMultipleToByteList(bytes,bytes)");
  } else if (addMultipleToStringList != addMultipleToStringListExpected) {
    failed("ABI doesn't match function: addMultipleToStringList(string,string)");
  } else if (testAlmostAll != testAlmostAllExpected) {
    failed("ABI doesn't match function: (uint256 item1, address item2, bool item3, bytes item4, string item5, string[] item6, address[] item7, bytes[] item8)");
  } else {
    passed();
  }

  std::cout << ((curPass) ? "PASSED" : "FAILED") << std::endl;
  logStream << "* Test: " << __func__ << std::endl
    << "* Expected Outputs: " << std::endl
    << "* " << addToAddressListExpected << std::endl
    << "* " << addToStringListExpected << std::endl
    << "* " << addToStringListFourExpected << std::endl
    << "* " << addToBytesListExpected << std::endl
    << "* " << addToBytesListFourExpected << std::endl
    << "* " << testMultipleByteArrayExpected << std::endl
    << "* " << addMultipleToByteListExpected << std::endl
    << "* " << addMultipleToStringListExpected << std::endl
    << "* " << testAlmostAllExpected << std::endl
    << "* Actual Outputs: " << std::endl
    << "* " << addToAddressList << std::endl
    << "* " << addToStringList << std::endl
    << "* " << addToStringListFour << std::endl
    << "* " << addToBytesList << std::endl
    << "* " << addToBytesListFour << std::endl
    << "* " << testMultipleByteArray << std::endl
    << "* " << addMultipleToByteList << std::endl
    << "* " << addMultipleToStringList << std::endl
    << "* " << testAlmostAll << std::endl
    << "* Test result: " <<
      ((curPass) ? "PASSED" : "FAILED - " + curReason)
    << std::endl << std::endl;

  return;
}

void Tests::loadAndTestContractNormal() {
  std::cout << "* Running test: " << __func__ << "... " << std::flush;
  Error e1, e2, e3, e4, e5, e6, e7, e8, e9;
  std::string const addToAddressListExpected = "0x5fd673e8000000000000000000000000000000000000000000000000000000000000002000000000000000000000000000000000000000000000000000000000000000020000000000000000000000002e913a79206280b3882860b3ef4df8204a62c8b10000000000000000000000002e913a79206280b3882860b3ef4df8204a62c8b1";
  std::string const addToStringListExpected = "0xece4955100000000000000000000000000000000000000000000000000000000000000200000000000000000000000000000000000000000000000000000000000000002000000000000000000000000000000000000000000000000000000000000004000000000000000000000000000000000000000000000000000000000000000c00000000000000000000000000000000000000000000000000000000000000052616161616161616161616161616161616161616161616161616161616161616161616161616161616161616161616161616161616161616161616161616161616161616161616161616161616161616161610000000000000000000000000000000000000000000000000000000000000000000000000000000000000000004f626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262620000000000000000000000000000000000";
  std::string const addToStringListFourExpected = "0xece4955100000000000000000000000000000000000000000000000000000000000000200000000000000000000000000000000000000000000000000000000000000004000000000000000000000000000000000000000000000000000000000000008000000000000000000000000000000000000000000000000000000000000000e0000000000000000000000000000000000000000000000000000000000000016000000000000000000000000000000000000000000000000000000000000001c0000000000000000000000000000000000000000000000000000000000000002461616161616161616161616161616161616161616161616161616161616161616161616100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000005862626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262000000000000000000000000000000000000000000000000000000000000000000000000000000286363636363636363636363636363636363636363636363636363636363636363636363636363636300000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000046464646400000000000000000000000000000000000000000000000000000000";
  std::string const addToBytesListExpected = "0x8ab94fd600000000000000000000000000000000000000000000000000000000000000200000000000000000000000000000000000000000000000000000000000000002000000000000000000000000000000000000000000000000000000000000004000000000000000000000000000000000000000000000000000000000000000800000000000000000000000000000000000000000000000000000000000000002aaaa0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002bbbb000000000000000000000000000000000000000000000000000000000000";
  std::string const addToBytesListFourExpected = "0x8ab94fd600000000000000000000000000000000000000000000000000000000000000200000000000000000000000000000000000000000000000000000000000000004000000000000000000000000000000000000000000000000000000000000008000000000000000000000000000000000000000000000000000000000000000c00000000000000000000000000000000000000000000000000000000000000100000000000000000000000000000000000000000000000000000000000000014000000000000000000000000000000000000000000000000000000000000000090aaaaaaaaaaaaaaaaa0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001fbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb0000000000000000000000000000000000000000000000000000000000000000020ccc00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000120ddddddddddddddddddddddddddddddddddd0000000000000000000000000000";
  std::string const testMultipleByteArrayExpected = "0x70afa559000000000000000000000000000000000000000000000000000000000000004000000000000000000000000000000000000000000000000000000000000001200000000000000000000000000000000000000000000000000000000000000002000000000000000000000000000000000000000000000000000000000000004000000000000000000000000000000000000000000000000000000000000000800000000000000000000000000000000000000000000000000000000000000002aaaa0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002bbbb0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002000000000000000000000000000000000000000000000000000000000000004000000000000000000000000000000000000000000000000000000000000000800000000000000000000000000000000000000000000000000000000000000002cccc0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002dddd000000000000000000000000000000000000000000000000000000000000";
  std::string const addMultipleToByteListExpected = "0xf953151e000000000000000000000000000000000000000000000000000000000000004000000000000000000000000000000000000000000000000000000000000000c00000000000000000000000000000000000000000000000000000000000000046aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002bbbb000000000000000000000000000000000000000000000000000000000000";
  std::string const addMultipleToStringListExpected = "0x4aee7a8d000000000000000000000000000000000000000000000000000000000000004000000000000000000000000000000000000000000000000000000000000000800000000000000000000000000000000000000000000000000000000000000003616161000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000036262620000000000000000000000000000000000000000000000000000000000";
  std::string const testAlmostAllExpected = "0x1608f4b100000000000000000000000000000000000000000000000000007614cf69b633000000000000000000000000c4ea73d428ab6589c36905d0f0b01f3051740ff800000000000000000000000000000000000000000000000000000000000000010000000000000000000000000000000000000000000000000000000000000100000000000000000000000000000000000000000000000000000000000000014000000000000000000000000000000000000000000000000000000000000002e0000000000000000000000000000000000000000000000000000000000000046000000000000000000000000000000000000000000000000000000000000004e00000000000000000000000000000000000000000000000000000000000000002aaaa000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000016d4c6f72656d20697073756d20646f6c6f722073697420616d65742c20636f6e73656374657475722061646970697363696e6720656c69742e2050656c6c656e746573717565206567657420706f72747469746f7220746f72746f722c2065742074696e636964756e74206e6962682e2041656e65616e2065726174207175616d2c206d6178696d757320696420677261766964612073697420616d65742c2072686f6e63757320736564206e756c6c612e20437572616269747572206d6178696d75732074656c6c7573206469616d2c2076656c2076756c7075746174652073617069656e206d6178696d75732076697461652e204475697320636f6e73656374657475722c2066656c69732061742065666669636974757220636f6e73656374657475722c20746f72746f72206e69736c20626962656e64756d206d61757269732c20656765742076656e656e61746973206175677565206a7573746f206574206f72636953696d706c6520000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000003000000000000000000000000000000000000000000000000000000000000006000000000000000000000000000000000000000000000000000000000000000a00000000000000000000000000000000000000000000000000000000000000120000000000000000000000000000000000000000000000000000000000000000561616161610000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000054626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262626262000000000000000000000000000000000000000000000000000000000000000000000000000000000000000363636300000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000003000000000000000000000000c4ea73d428ab6589c36905d0f0b01f3051740ff8000000000000000000000000c4ea73d428ab6589c36905d0f0b01f3051740ff8000000000000000000000000c4ea73d428ab6589c36905d0f0b01f3051740ff80000000000000000000000000000000000000000000000000000000000000003000000000000000000000000000000000000000000000000000000000000006000000000000000000000000000000000000000000000000000000000000000a000000000000000000000000000000000000000000000000000000000000000e000000000000000000000000000000000000000000000000000000000000000020aaa00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000020bbb0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000021aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa00000000000000000000000000000000000000000000000000000000000000";

  boost::filesystem::path contractPath(
    boost::filesystem::current_path().parent_path().string()
    + "/tests/ArrayTest.json"
  );
  json contractJson = Utils::readJSONFile(contractPath);
  Contract ArrayTest(contractJson, "0x0000000000000000000000000000000000000000");
  std::string addToAddressList = ArrayTest(
    json::array({
      json::array({
        "0x2E913a79206280B3882860B3eF4dF8204a62C8B1",
        "0x2E913a79206280B3882860B3eF4dF8204a62C8B1"
      })
    })
  , "addToAddressListArr", e1);

  std::string addToStringList = ArrayTest(
    json::array({
      json::array({
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
        "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"
      })
    })
  , "addToStringListArr", e2);

  std::string addToStringListFour = ArrayTest(
    json::array({
      json::array({
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
        "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
        "cccccccccccccccccccccccccccccccccccccccc",
        "dddd"
      })
    })
  , "addToStringListArr", e3);

  std::string addToBytesList = ArrayTest(
    json::array({
      json::array({
        "0xaaaa",
        "0xbbbb"
      })
    })
  , "addToByteListArr", e4);

  std::string addToBytesListFour = ArrayTest(
    json::array({
      json::array({
        "0xaaaaaaaaaaaaaaaaa",
        "0xbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
        "0xccc",
        "0xddddddddddddddddddddddddddddddddddd"
      })
    })
  , "addToByteListArr", e5);

  std::string testMultipleByteArray = ArrayTest(
    json::array({
      json::array({
        "0xaaaa",
        "0xbbbb"
      }),
      json::array({
        "0xcccc",
        "0xdddd"
      })
    })
  , "testMultipleByteArray", e6);

  std::string addMultipleToByteList = ArrayTest(
    json::array({
      "0xaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
      "0xbbbb"
    })
  , "addMultipleToByteList", e7);

  std::string addMultipleToStringList = ArrayTest(
    json::array({
      "aaa",
      "bbb"
    })
  , "addMultipleToStringList", e8);

  // This should do it lmao.
  // testAlmostAll(uint256 item1, address item2, bool item3, bytes item4, string item5, string[] item6, address[] item7, bytes[] item8)
  std::string testAlmostAll = ArrayTest(
    json::array({
      "129831751235123",
      "0xc4ea73d428ab6589c36905d0f0b01f3051740ff8",
      "1",
      "0xaaaa",
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Pellentesque eget porttitor tortor, et tincidunt nibh. Aenean erat quam, maximus id gravida sit amet, rhoncus sed nulla. Curabitur maximus tellus diam, vel vulputate sapien maximus vitae. Duis consectetur, felis at efficitur consectetur, tortor nisl bibendum mauris, eget venenatis augue justo et orciSimple ",
      json::array({
        "aaaaa",
        "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
        "ccc"
      }),
      json::array({
        "0xc4ea73d428ab6589c36905d0f0b01f3051740ff8",
        "0xc4ea73d428ab6589c36905d0f0b01f3051740ff8",
        "0xc4ea73d428ab6589c36905d0f0b01f3051740ff8"
      }),
      json::array({
        "0xaaa",
        "0xbbb",
        "0xaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      })
    })
    , "testAlmostAll", e9);

  if (e1.getCode() != 0) {
    failed(e1.what());
  } else if (e2.getCode() != 0) {
    failed(e2.what());
  } else if (e3.getCode() != 0) {
    failed(e3.what());
  } else if (e4.getCode() != 0) {
    failed(e4.what());
  } else if (e5.getCode() != 0) {
    failed(e5.what());
  } else if (e6.getCode() != 0) {
    failed(e6.what());
  } else if (e7.getCode() != 0) {
    failed(e7.what());
  } else if (e8.getCode() != 0) {
    failed(e8.what());
  } else if (e9.getCode() != 0) {
    failed(e9.what());
  } else if (addToAddressList != addToAddressListExpected) {
    failed("ABI doesn't match function: addToAddressListArr(address[]) two items");
  } else if (addToStringList != addToStringListExpected) {
    failed("ABI doesn't match function: addToStringListArr(string[]) two items");
  } else if (addToStringListFour != addToStringListFourExpected) {
    failed("ABI doesn't match function: addToStringListArr(string[]) four items");
  } else if (addToBytesList != addToBytesListExpected) {
    failed("ABI doesn't match function: addToByteListArr(bytes[]) two items");
  } else if (addToBytesListFour != addToBytesListFourExpected) {
    failed("ABI doesn't match function: addToByteListArr(bytes[]) four items");
  } else if (testMultipleByteArray != testMultipleByteArrayExpected) {
    failed("ABI doesn't match function: testMultipleByteArray(bytes[],bytes[])");
  } else if (addMultipleToByteList != addMultipleToByteListExpected) {
    failed("ABI doesn't match function: addMultipleToByteList(bytes,bytes)");
  } else if (addMultipleToStringList != addMultipleToStringListExpected) {
    failed("ABI doesn't match function: addMultipleToStringList(string,string)");
  } else if (testAlmostAll != testAlmostAllExpected) {
    failed("ABI doesn't match function: (uint256 item1, address item2, bool item3, bytes item4, string item5, string[] item6, address[] item7, bytes[] item8)");
  } else {
    passed();
  }

  std::cout << ((curPass) ? "PASSED" : "FAILED") << std::endl;
  logStream << "* Test: " << __func__ << std::endl
    << "* Expected Outputs: " << std::endl
    << "* " << addToAddressListExpected << std::endl
    << "* " << addToStringListExpected << std::endl
    << "* " << addToStringListFourExpected << std::endl
    << "* " << addToBytesListExpected << std::endl
    << "* " << addToBytesListFourExpected << std::endl
    << "* " << testMultipleByteArrayExpected << std::endl
    << "* " << addMultipleToByteListExpected << std::endl
    << "* " << addMultipleToStringListExpected << std::endl
    << "* " << testAlmostAllExpected << std::endl
    << "* Actual Outputs: " << std::endl
    << "* " << addToAddressList << std::endl
    << "* " << addToStringList << std::endl
    << "* " << addToStringListFour << std::endl
    << "* " << addToBytesList << std::endl
    << "* " << addToBytesListFour << std::endl
    << "* " << testMultipleByteArray << std::endl
    << "* " << addMultipleToByteList << std::endl
    << "* " << addMultipleToStringList << std::endl
    << "* " << testAlmostAll << std::endl
    << "* Test result: " <<
      ((curPass) ? "PASSED" : "FAILED - " + curReason)
    << std::endl << std::endl;

  return;
}

