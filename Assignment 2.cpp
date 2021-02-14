<!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
    <title> Poke Dextr </title>
  </head>

  <body onload="displayPokemon('dugtrio')" style="font-family:'Times New Roman', Times, serif, ;background-color: rosybrown">
    <script>
        async function getPokemon(pokemonName){
  
            let url = "https://pokeapi.co/api/v2/pokemon/";
            var pokemon;
            let pokeArr=[];
            url=url+pokemonName;
            try{
              let response = await fetch(url);
              let info = await response.json();
              document.getElementById("result").innerHTML=`<img src="${info.sprites.front_default}" height="400" width="400"> <li> ${pokemonName} # ${info.id} </li>`
              if (info.types[0].slot == "2") {
                document.getElementById("result").innerHTML+=`<li>Type 1: ${info.types[1].type.name} </li>
                <li>Type 2: ${info.types[0].type.name} </li>`
              }
              else {
                 document.getElementById("result").innerHTML+=`<li>Type 1: ${info.types[0].type.name} </li>`
              }
              document.getElementById("result").innerHTML+=`<li>Weight: ${info.weight} </li> <li>Height: ${info.height}</li>`
            }catch(e){
              console.log(e);
          }

        }

        async function getListing(){
          //performs an ajax request to the spcified url to get pokemon data then pass it to displayListing()
          try{
              let response = await fetch("https://pokeapi.co/api/v2/pokemon/?limit=50&offset=50");
              let result = await response.json();
              displayListing(result)
            }catch(e){
              console.log(e);
            }
        }

        function displayListing(result){
           //Renders a list of pokemon links to the page  
          let list=document.getElementById("listing").innerHTML;
          let i=0;
          for (i=0; i<50; i++) {
            list=list+`<li><a style="text-decoration:none" class="collection-item" href="#" id="${result.results[i].name}" onclick=displayPokemon("${result.results[i].name}")>${result.results[i].name}</a></li>`;
          }
          document.getElementById("listing").innerHTML=list;
        }

        function displayPokemon(pokemon){
          getPokemon(pokemon)
        }

        getListing();
       
    </script>
    <nav>
        <p style="font-size:50px">Poke Dextr</p>
        <a href="index.html" style="font-size:25px;text-decoration: rgb(20, 110, 110)">Listing</a>
    </nav> 
    <main>
        <div id="listing" style="width:150px;max-height:600px;line-height:3em;overflow:scroll;padding:5px;float:left;list-style-type:none;background-color:white">
        </div>
        <div id="result" style="float:right;list-style-type:none;background-color: White ">
        </div>
    </main>
        
  </body>
</html>
