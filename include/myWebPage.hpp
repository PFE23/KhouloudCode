#ifndef MYWEBPAGE_HPP
#define MYWEBPAGE_HPP
const char myPage[] PROGMEM = R"===(
<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Cycles</title>
  <style>
    * {
      background-color: black;
      margin: 0;
    }

    .nbPC {
      text-align: center;
    }

    .nbPCHolder {
      background-color: white;
      display: inline-block;
      padding: 10px;
      text-decoration: none;
      height: auto;
      border-radius: 20px;
    }

    .nbPCHolder h1 {
      color: black;
      background-color: inherit;
      min-width: 55px;
    }

    .container {
      display: flex;
    }

    .clock {
      margin-left: auto;
      margin-right: auto;
      margin-top: 2px;
      display: inline-block;
      padding: 0px;
      background-color: red;
      max-width: 150px;
      align-items: center;
    }

    .message {
      background-color: #2A265F;
      color: #fff;
      font-family: JasmineUPC;
      font-size: 25px;
      text-decoration: none;
      margin: 0px;
      text-align: center;
      border-radius: 10px 10px 0 0;
    }

    .content {
      font-family: JasmineUPC;
      background-color: black;
      color: #17D4FE;
      font-size: 35px;
      position: relatif;
      border-radius: 0 0 10px 10px;
      padding: 4px;
    }

    p {
      color: white;
    }

    table {

      border-collapse: collapse;
      width: 100%;
      position: center;
    }

    td,
    th {
      text-align: center;
      border: 1px solid #dddddd;
      padding: 8px;
      color: white;
    }
  </style>
</head>

<body>
  <div class="nbPC">
    <div class="nbPCHolder" id="nbPiecesH" style="background-color: red;">
      <h1 class="nbP" id="nbCycles">0</h1>
    </div>
  </div>
  <div class="container">
    <div class="clock">
      <div class="message">Min. Cycle</div>
      <div class="content"><time id="minCycle">00:11:22</time></div>
    </div>
    <div class="clock">
      <div class="message">Max. Cycle</div>
      <div class="content"><time id="maxCycle">00:11:22</time></div>
    </div>
  </div>
  <div class="container">
    <div class="clock" style="background-color: green;">
      <div class="message">Total work</div>
      <div class="content"><time id="totalWorkingTime">00:11:22</time></div>
    </div>
    <div class="clock" style="background-color: green;">
      <div class="message">Total pause</div>
      <div class="content"><time id="totalSleepingTime">00:11:22</time></div>
    </div>
  </div>
  
  <table id="tableauDonnees">
    <thead>
      <tr>
        <th> Num cycle </th>
        <th> Départ cycle </th>
        <th> Fin cycle </th>
        <th> Durée cycle </th>
    </thead>
    <tbody>
    </tbody>
    </tr>
  </table>
  <script>
    var Socket;
    var bPrint = false;
    function init() {
      Socket = new WebSocket('ws://' + window.location.hostname + ':81/');
      Socket.onmessage = function (event) {
        processCommand(event);
      };
    }
    function processCommand(event) {
      var obj = JSON.parse(event.data);
      document.getElementById('nbCycles').innerHTML = obj.nbCycles;
      /*document.getElementById('starTime').innerHTML = obj.starTime;
      document.getElementById('endTime').innerHTML = obj.endTime;
      document.getElementById('currentCycle').innerHTML = obj.currentCycle;*/
      document.getElementById('minCycle').innerHTML = obj.minCycle;
      document.getElementById('maxCycle').innerHTML = obj.maxCycle;
      document.getElementById('totalWorkingTime').innerHTML = obj.totalWorkingTime;
      document.getElementById('totalSleepingTime').innerHTML = obj.totalSleepingTime;
      //console.log(event.data);

      if (obj.starTime > obj.endTime) {
        document.getElementById('nbPiecesH').style.backgroundColor = "red";
      } else {
        document.getElementById('nbPiecesH').style.backgroundColor = "white";
      }
      if (bPrint) {
        var tableauDonnees = document.getElementById("tableauDonnees");
        var nouvelleLigne = tableauDonnees.insertRow(1);
        var colonnenbCycles = nouvelleLigne.insertCell(0);
        var colonnestartTime = nouvelleLigne.insertCell(1);
        var colonneendTime = nouvelleLigne.insertCell(2);
        var colonneCurrentCycle = nouvelleLigne.insertCell(3);

        colonnenbCycles.innerHTML = obj.nbCycles;
        colonnestartTime.innerHTML = obj.starTime;
        colonneendTime.innerHTML = obj.endTime;
        colonneCurrentCycle.innerHTML = obj.currentCycle;

        
        /*console.log(obj.starTime);
        console.log(obj.endTime);
        console.log(obj.currentCycle);*/
      }
      bPrint = !bPrint;


    }
    window.onload = function (event) {
      init();
    }
  </script>



</body>

</html>
<!--Aharoni
p.b {
  font-family: JasmineUPC;
  background-color: black;
  color: #17D4FE;
  font-size: 40px;
  width: 125px;
}
-->
)===";
#endif