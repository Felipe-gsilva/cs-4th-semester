const { convertArrayToCSV } = require("convert-array-to-csv");
const fs = require("fs");
const { getResultsFrom } = require("./getResultsFrom");

const SPLITER = ",";
const UMA_SEMANA = 604800000 / 7; // 1000 * 60 * 60 * 24 * 7

const header = [
    "idPartida", "idVencedor", "resultado", "rankingTimeGanhou", "rankingTimePerdeu",
    ["vencedor1", "vencedor2", "vencedor3", "vencedor4", "vencedor5"].map(p => [p + "Nome", p + "Id"]).flat(),
    ["perdedor1", "perdedor2", "perdedor3", "perdedor4", "perdedor5"].map(p => [p + "Nome", p + "Id"]).flat(),
    "MOTM", "estrelas"
].flat();

const addZero = int => int < 10 ? "0" + int : int;

/**
 * @param {Date} date
 * @returns { string }
 */
const dateToString = date => date.getUTCFullYear() + "-" + addZero(date.getUTCDate()) + "-" + addZero(1 + date.getUTCMonth());

let startDate = new Date("2016-01-01");
let endDate = new Date(startDate.getTime() + UMA_SEMANA);

const fun = async (startDate, endDate) => {
    try {
        console.log({startDate, endDate})
        const matchesArr = await getResultsFrom({ startDate, endDate });
        console.log("arr length: ", matchesArr.length)
        if (matchesArr.length > 0) {
            const csv = matchesArr.map(matchArr => matchArr.join(SPLITER)).join("\n");
            fs.appendFile("output.csv", csv + "\n", err => console.log(err ? ("erro:", { err }) : "Sucesso"));
        } else {
            return false;
        }
        
        return true;
    } catch (err) {
        console.log("erro", { err });
        return false;
    }
};

const rec = async () => {
    const call = await fun(dateToString(startDate), dateToString(endDate));

    if (call === true) {
        startDate = endDate;
        endDate = new Date(startDate.getTime() + UMA_SEMANA);
        await rec();
    } else {
        await fun(dateToString(startDate), dateToString(endDate));
    }
}

rec();
