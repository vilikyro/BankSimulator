const express = require('express');
const tilitapahtumat = require('../models/Tilitapahtumat_model');
const router = express.Router();
const Tilitapahtumat = require('../models/Tilitapahtumat_model');

router.get('/:id?',
 function(request, response) {
  if (request.params.id) {
    Tilitapahtumat.getById(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  } else {
    Tilitapahtumat.getAll(function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }
});

router.post('/debit_nosto', 
function(request, response) {
  tilitapahtumat.debit_nosto(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});

router.post('/debit_talletus', 
function(request, response) {
  tilitapahtumat.debit_talletus(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});


router.post('/credit_nosto', 
function(request, response) {
  tilitapahtumat.credit_nosto(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});

router.post('/credit_maksu', 
function(request, response) {
  tilitapahtumat.credit_maksu(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});

router.get('/10Tapahtumaa/:id?',
 function(request, response) {
  if (request.params.id) {
    Tilitapahtumat.get10Tapahtumaa(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  } 
});

router.get('/10debitTapahtumaa/:id?',
 function(request, response) {
  if (request.params.id) {
    Tilitapahtumat.get10debitTapahtumaa(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  } 
});

router.get('/10creditTapahtumaa/:id?',
 function(request, response) {
  if (request.params.id) {
    Tilitapahtumat.get10creditTapahtumaa(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  } 
});

router.get('/5Tapahtumaa/:id?',
 function(request, response) {
  if (request.params.id) {
    Tilitapahtumat.get5Tapahtumaa(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  } 
});

router.post('/', 
function(request, response) {
  Tilitapahtumat.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});


router.delete('/:id', 
function(request, response) {
  Tilitapahtumat.delete(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/:id', 
function(request, response) {
  Tilitapahtumat.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

module.exports = router;