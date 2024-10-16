const { HLTV } = require("hltv");

/**
 * @param { { endDate, startDate } } date
 * @returns { Promise<any[]>[] }
 */
 const getResultsFrom = async date => {
    const allMatches = await HLTV.getResults(date);
    const matches = allMatches.filter(match => match.format === "bo3");
    const matchesArr = [];

    for (const m of matches) {
        const match = await HLTV.getMatch(m);
        const [vencedor, perdedor] = match.winnerTeam?.id === match.team1.id ? ["team1", "team2"] : ["team2", "team1"];
        
        matchesArr.push([
            match.id,                                                   // id da partida
            match.winnerTeam?.id,                                       // id do time que ganhou
            `${m.result[vencedor]}x${m.result[perdedor]}`,              // resultado
            match[vencedor].rank ? match[vencedor].rank : -1,           // ranking do time que ganhou
            match[perdedor].rank ? match[perdedor].rank : -1,           // ranking do time que perdeu
            match.players[vencedor].map(p => [p.name, p?.id]).flat(),   // players vencedores
            match.players[perdedor].map(p => [p.name, p?.id]).flat(),   // players perdedores
            match.playerOfTheMatch?.id,                                 // motm
            m.stars                                                     // estrelas
        ].flat());
    }
    
    return matchesArr;
};

module.exports = { getResultsFrom };
