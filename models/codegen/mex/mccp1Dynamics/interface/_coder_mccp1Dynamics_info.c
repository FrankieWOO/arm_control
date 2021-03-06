/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_mccp1Dynamics_info.c
 *
 * Code generation for function '_coder_mccp1Dynamics_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mccp1Dynamics.h"
#include "_coder_mccp1Dynamics_info.h"

/* Function Definitions */
mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xResult;
  mxArray *xEntryPoints;
  const char * fldNames[4] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs" };

  mxArray *xInputs;
  const char * b_fldNames[4] = { "Version", "ResolvedFunctions", "EntryPoints",
    "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 4, fldNames);
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 0, "Name", mxCreateString("mccp1Dynamics"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", mxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", mxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  xResult = emlrtCreateStructMatrix(1, 1, 4, b_fldNames);
  emlrtSetField(xResult, 0, "Version", mxCreateString("9.2.0.556344 (R2017a)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[28] = {
    "789ced5dcd6fe3c615e7e6abd9166988a24db04dda669360d174114bb6654bdea68df56549b625ebcb5ed94121531425d3e29748eac33ef990023df4b0e8a987"
    "1e849e1a20871c72e8b17f404f059a16450bf450a0a7023df55c4a146d93d144b2488d44ea3d60314b3f717ea3a7991f67debc7924eea5d2f70882f826a1cbe9",
    "1bf706e52bc36b72583e4798c5aabf372cfd966b435e245e30dd67e87f332c69515099aeaa5f70acc0645a7c8591b50b81e299eb6aaa22cf0a94a0162f248690"
    "1945e4da4c75a0a9b11c536479665fbc759164b50b7ee796eafaa2afeaff3f7ac6d08d428b27e433e5a6b9dced0be2967d3e437cff1726b44f0a611fd2a2ff28",
    "feb3d8135f4c16a58ad8f57544b9a14814cdf83a4a99a7548eaaf828992ff7ad268b9c8f17ab0ca7f8789a965663179ac5585a59e11faa542b6c69ff29a27d2f"
    "4dd87e6b69c87de2e55b572bdbe3f026b5d7f3083c72a8515861503a85f792e5fa064fd754c55685636ef07a36f1b6907866fd47a9fdd2a04ba4c3c5fd70c497",
    "5ff3af06299f2a8a5cbf83303ce7e3d88a6fd83718aed6127c9a6d56f8e1fd187ffff7638ffe1cc6dbdf70f7eff9e17511f54ddadf5e43e091163d452523279d"
    "46923d4a475b5c2422c482d94ceca61dd93138e3da4120ae71d5df43dcbfc4e3569377af79fb0a51dfa4f67980c0232d7a5a7b72c92bacf6f097058a5b51688a",
    "a3e41583d5edf3ba5550ed31c4c0fbdd947846fdf13178867e82fed1fff7786027df63c350bec7baa5aefb0abe7e72f5e9c79f00bfbb9ddffd1bc9cd50b4f374"
    "cd1fe97438bfc40562f5cb08f0fbb2f0fb33447d93dae73d041e69d15bf89d9224eea230a0ae9d9640abac28a4842ca7ad6c869f37da27d96cdfab63da67e86b",
    "c35694cf28a1aa4dec0dfcdfdbc42f8ec137f4d3f23fda907ad7c2d8afa87ffc0d9e076e7f1e243bb168be1bba5c17a924b3bba386e8835a24e19de7018ce7d1"
    "a52128ffcd15a23eb7ad03a6f5efc03ac02cb00ec08307eb0067ea077ffde8f69bfb9ddf317ffd387ee525b1d3dfd671abbffe0912cfacbfdbba5094b4ce30b0",
    "8cb130c4c8e36fee3c001e773b8f972e370fd36a9ca5f8ad662728e6d6693a1f8a7a87c77b88fb1775dca2fc1793f6b3e72cd786dcb77c5e17ffb65eae39366f"
    "ff01029fb4e82df3765689b4584e4d099916cfc82c3d379eb7fbdcdf45e299f5d3cedbad869a03efbff32ff0dbb89ef70fdacd68b8966c878ab9c0051de785b5",
    "9d132e09bcefddf95a5f3e746cbefeb2e59ab8fe9cae6115ed2bcb6cd7adf3f59f22f1ccfabbeee368fff119b6e9f7018cbf7f0dfcedeee7edb64aa765563ce4"
    "37d62e85c6d1fe56275d4aee006f7b9ab7af228ef1f68b083c72a819ba595ceb6799cdfe7bfff737fdfc38e7db9fffea8fc0db8bcadbdf41e09116fdf1a1ffdc",
    "9f66536b72aabe7b9c086d8562a5a704f0f6bcc62d5e3fcbdbdb7af908fc2cc3bf839f6574fbc1cf82070ffc2cced46f37ce2182a89fb4e8a7e6fd87354e3526"
    "b504ee797b7adba9fef63a028fb4e847c6c3c4ebae8d8371b07f8ce479c34073e0f7fbbffc3bf0bbdbf9dd9fe904f922cb9fecb1f96a7c2f46176ab50b0fc5c1",
    "c0f8350b8adf51eb8949edf48ae59ab07cced0b38aa04f48d5fe4966f7c63786917866fd84cffd1adb65aa92a8750b9fc942f3382ff100e262dccfeb89f5c645"
    "a15967b96831dac83723f562e330eea173acc0eb6641f13a0acfb97dd21aab2d5acedcea6fff008967d64fc3e3ba65b09f6300fe9e211e2e7f7bbbc9c4a536ad",
    "6c953aeba298550aabebc7278477f87bd1fda737fcfdb0c6ca8a5a63cded3f45b4cfd17ef78753c7fceddf47e09116bd668cb26684724d94395194ca629b916b"
    "9cd829d3fd7c41f3cb4b60f71c5b7e0c9ea1bf633c8cde7dbec26273f0cb7cfa9717bf00fe9f111eaef9bbb217efc6639797d9ddee5a20bde68fe6c2abfeb877",
    "f8ffaf88fb27b563d7724d583e67e89d1fcf0fbffa03e533869318196fff4c3836df7fc1724d5c7f4ed7f467b5fd72cefb02ac5065ba2941bd6ec7af6db62334"
    "a61d867eba75c00a8fb13fbc0bfbaeeee7ffc285c4f21bcdfcd355b6520da44e72d9f46adb43fe1b18afa3cfa1badd0f3feef9419f51839d6cf0c38f6e37f871",
    "f0e0811fde99fa611e3fd9f79cac7fa6b0e523d0be384f75e7c7fb3d9b780efbedcde79b06b6c1eeb77f03f8defd7ccf75374f18fff981ff908df88b9dcb552a"
    "c0653d142f097c3fd9f79ca87f5ee1e5fb7e5231e0fbd17c6fa42605bef7061e2ebedf48a51b5223c374d564ba50cf26f6b2093fe7a1f8c9cf10f7c33eedad7e",
    "f7cf53c778fcaefe77bb78778db701bf1df8d971e0819fdd99fa17284e72f1ce3711377192bf40d437a99dde46e09116fdf8bcf0fae79cda0fb09b0fdeeef33f"
    "3d06dfd03b983f1a733e6002ceb9ce100fd77320ceb3c570e02252e524662fbd55978e053602f3f8651ac704b19d772cdef20d041e69d18f38efca74a530c789",
    "f440efd6f3513b483cb3decebacf3014de3c6490d7609678b8f83e5509a75637a5463b7ed47cea6f44fc811cbbeb21be87f16b1654bccd9ce6fdb7bf7e468cea"
    "b1f57d9917df2ffafc6084c170bff703787f8678b8785f5ddbbb2835eba5a3b37a23984fa88ddd6c37eea1fd59bbe3781f513f69d14fefefd13df6e51a27526a",
    "f9daf383f75cd511e4b5b189e7ddf3d390d766967890d7c699faedf2fc01a27ed2a2b7efd72f57459e62853223cba28c99e7738eedcb8ecb3bcc2a02d577ddcf"
    "8bcf7b36f17e8cc433eba7cb17afd96648e418791cf6676788872b0f4233dc3ae00317a5803f2fafb5a2abcc569bcf10dee1f11ee2fee51db77db9795ff715a2",
    "3ec8333c191ee419761a4f9765c1833cc3ced40ff3f5d1ed9fd77cbdc689a29bdf1332abe77ead25f806b6c1ffdc7f3ff60878dced3c1e6a060f8a4d2eb6d188"
    "9c15738982da8cc56878bf9397c7ad266fc17c7df87798af8f6e3fccd7f1e0c17cdd99fa7b88fb979be79df3cbd8888fa4e41563f63ebf7c9476f74f1363f00c",
    "fdb43cff58b7d4755fc1c8efafc1b956f7f37be56c335b1238b55a10f9784b48ae57e291dd04f0fbb2f0fb33447d93dae73d041e69d18f3f0f9512b21c4533c3"
    "cf2fcab928bbf9888b63f00dbd83e7298686c49ee78082f776bbff7990ecc4a2f96ee8725da492ccee8e1aa20f6a110f3d0f603c8f2e0d31f7bf15cfad03a6f5",
    "f7c03ac02cb00ec08307eb0067ea5fa038e8c5cb8f7095712c4efedb083cd2a2b7f0bcbe094db8376fd987483cb37e5a7e1f18082faf53450678ddedbcde0ac4"
    "0f4b6badbdae92395322e9f3c2a6b2c1407cfc757d2944fda445ffd160d0c66451ea0fd38e283714499b94fb3a4a79c8e594cc976951506591f3f1dae8e5141f",
    "4fd3d26aec42a0789656348a57a956d8d2fe5344fb66750e168537a9bd9e47e091430d2d2a83d2adf1365b483cb37e1a7f9f669b79e49787789b19e2e1e271a9"
    "d83d0f1ea8d9cde001552c9c17e5c4052d7888c77b88fb9778dc124eeec33e40e09116fd68ff8bc1eaeedd878d8fc133f476fd2f465fc1d84f7efbf127c0ef6e",
    "e7f790bcaf50393a7dfcb4725caa44229b815add4bf3f41ee27ee0775d9e21ea837d585d60df66746908ecc3e2c1837d5867ea87f13cba346456fbb08bb20e98"
    "d6bf03eb00b3c03a000f1eac039ca91ffcf5a3db3f2b7ffdb87d50a529abfdd2adfefa27483cb37e9a7561df36f8cf4d81bf7e9678b8783c9088d7cefc9ba9f3",
    "83f87a4acde604a11d8dc1b9292f8f5b4d1e39364f7f1381475af45f3a1f1b1b6475885be369e6edbf59f4f84993e1b0c6d910fff9e00be07bb7f37db292ca67"
    "94e07a309f61c5927474d43eaa64e1fd52cb307e350938365f7fd9724d5c7f4ed7b08ab68e9115c6adf3f56d249e597fb7e77edf26fd27bf611d9cef07bcfa46",
    "fe7fc0df6ee7ef0d2e9fec88e95062fd30590fd2d1cbdd7caae021bf4b0f71ff72cfd77f0871ef36f120eedd2e9e2ecb820771efced4df43dcbfdc7ceedc3ee9"
    "771178a4453f7a9fd4f0aabb375e72d6ef0533f6498dbe8291dfdff9d3bf81df1795df27cd171f6aed17fc47eb076139b51e174abbf94d21bf4900bf2f0bbf3f",
    "43d407f192ba407cd5e8d2108897c48307f192ced40fe379746988d7d701d3faeb611d60165807e0c183758033f57f86b81fe22547f33d0a6f527b7d0d81470e"
    "3572956db355666e7cdeb389379b7ca6fd3c4643cbe07fffdfeb5fcf018fbb9ec73bb9da6129b0194cb6b9fc562c14da170f69c23b3cde43dcbfa8e316e5bf98",
    "b49f3d8768ef7dcbe775797b5b2f9d8b9f84f78ba0f0cc7a78bfc8a478ba2c0b1ebc5fc499fa7b88fb1795f74f11ed71b69ffdc8319e7f0b81475af423fc334c"
    "578a8abc44a9acc6bc6ee5f93d249e593f2dcf7fc950f8fbcbeb905fd8fd3c5fe91e67f235aa71944bef6576f38c5af0170e80e73dcef34f1c8baffc16028fb4",
    "e82d3caf7d77fdef6ef5d7fc048967d64fcbef9a8130e729b87a15fc35eee7f3f4a1ea3f4e3d0d0bc2619ecd2ab94c5d2936e3dee173bbf3b27d44fda445ef88"
    "dfbd2e536d56bdb8ddfe5344fb9ced771b8ef9ddc7e51556586150ba95c76799bf4eb30de415f6181e2e1ea7a864e4a4d348b247e9688b8b448458309bf1d0b9",
    "556c7e5427789ca2698633b7ff14d1be59e52d40e139757e951f2e47dccae31f20f1ccfabbafd30ccbac48fdfb31fefe3f7ff2d6175ee6f1efcdd37f846bffb4"
    "7b7c7212af8759b91968f3f18de27138774e11dee1f11ee2fe251eb79afcf743887b990ccf7bfe35887b99251ec4bdd8abfffffe560bc7",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 72568U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_mccp1Dynamics_info.c) */
