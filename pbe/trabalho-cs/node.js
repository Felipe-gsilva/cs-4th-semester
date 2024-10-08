const { HLTV } = require('hltv')

const a = HLTV.getResults({startDate: "2016-01-01", endDate: "2024-12-31"}).then((res) =>  {
    console.log(res.filter(r => r.format == 'bo3'))
)



