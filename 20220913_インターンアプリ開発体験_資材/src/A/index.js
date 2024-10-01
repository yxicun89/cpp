const videoEnabled = false;

const name = '高田康宏'
document.getElementById('title').innerHTML = `${name}'s Faces App` 

/**
 * 課題(1)
 * 画像イメージをURLとして読み込む.
 */
const imageLoader = imageElement => {
  //課題(1) 下の???を正しいものに直す
  const player = document.getElementById("player");
  const reader = new FileReader();
  reader.addEventListener("load", () => player.src = reader.result, false);
  const file = imageElement.files[0];
  if (file) {
    reader.readAsDataURL(file);
  }
};

$(function() {
  // ファイルから画像を取得
  if (!videoEnabled) {
    // ファイル選択からイメージを読み込み
    const imageElement = document.getElementById("image");
    imageElement.addEventListener("change", ev => {
      imageLoader(ev.target);
    });
  }

  //課題(2) 撮影ボタンを押したら静止画を撮影して、映像の隣に静止画が表示されるようにする
  document.getElementById('captureButton').addEventListener('click', (ev) => {
    const canvas = document.getElementById("snapshot");
    const ctx = canvas.getContext("2d");
    const player = document.getElementById("player")

    // 画像を描く
    ctx.drawImage(player, 0, 0, canvas.width, canvas.height);
    faceApi(canvas.toDataURL());
  })
});

//課題(3) 撮影した静止画を使って解析APIを呼び出す
const faceApi = function(sourceImage) {
  //FaceApi呼び出し
  $.ajax({
    url: uriBase + "?" + $.param(params),
    beforeSend: function(xhrObj) {
      xhrObj.setRequestHeader("Content-Type", "application/octet-stream");
      xhrObj.setRequestHeader("Ocp-Apim-Subscription-Key", subscriptionKey);
    },
    type: "POST",
    data: makeblob(sourceImage),
    processData: false
  })
    .done(function(data) {
      // API呼び出し結果 画面表示
      //➀textAreaという変数を作って、結果を表示したいHTML側の枠の要素（Id）を設定する
      //ここに書く！
const textArea = document.getElementById('responseTextArea')
      textArea.innerText = JSON.stringify(data);
      // 枠線表示
      drawFaceline(data);
    })
    .fail(function(error) {
      alert("error");
      console.error(error);
    });
};

//課題４：顔に枠を出す処理部分を書き、解析結果表示の時に呼び出すようにする
//顔枠線処理//
const drawFaceline = function(data) {

  data.forEach(function(element, index) {
    //顔の位置座標を設定
    const faceRe = element.faceRectangle;
    //➀faceReに格納されている顔の位置情報を、それぞれleft,top,width,heightという変数を作ってそこに設定する。
    const [left, top, width, height] = "left,top,width,height".split(",").map(key => faceRe[key]);

    //➁変数"canvas"を作り、顔枠を出したい静止画の要素を取得して設定する
    const canvas = document.getElementById("snapshot");

    const ctx = canvas.getContext("2d");
    //枠線の色や太さの設定
    ctx.lineWidth = 2;
    //➂枠線の色を設定する（RGB方式）
    ctx.strokeStyle = "rgb(123, 23, 45)";
    ctx.strokeRect(left, top, width, height);
    // 番号を表示
    //➃枠線の上に表示する数字の色を設定する（RGB方式）
    ctx.fillStyle = "rgb(123, 23, 45)";
    ctx.font = "bold 32px 'Arial'";
    ctx.fillText(index + 1, left, top);
  });
};

//引数の画像をBase64に変換
const makeblob = function(dataURL) {
  const BASE64_MARKER = ";base64,";
  if (dataURL.indexOf(BASE64_MARKER) == -1) {
    const parts = dataURL.split(",");
    const contentType = parts[0].split(":")[1];
    const raw = decodeURIComponent(parts[1]);
    return new Blob([raw], { type: contentType });
  }
  const parts = dataURL.split(BASE64_MARKER);
  const contentType = parts[0].split(":")[1];
  const raw = window.atob(parts[1]);
  const rawLength = raw.length;

  const uInt8Array = new Uint8Array(rawLength);

  for (let i = 0; i < rawLength; ++i) {
    uInt8Array[i] = raw.charCodeAt(i);
  }

  return new Blob([uInt8Array], { type: contentType });
};

// おまけ
// ビデオから映像取得
// オンラインではカメラが有効でない可能性があるため、今回は使用しません。
// 興味がある方は自力でやってみてください。
if (videoEnabled) {
  // 画像
  document.getElementById("player").remove();
  document.querySelector("input#image").remove();
  document.getElementById("captureButton").innerHTML = "撮影する";
  document.getElementById("player-wrapper").innerHTML =
    '<video id="player" autoplay style="height: 96%; width: 100%"></video>';

  navigator.mediaDevices
    .getUserMedia({ video: true })
    .then(function(stream) {
      //ページ上で再生
      //課題(1) 下の???を正しいものに直す
      const player = document.getElementById("player");

      player.srcObject = stream;
    })
    .catch(function(error) {
      console.error("video initialize error", error);
    });
}

// APIのKeyなどの設定
const subscriptionKey = "ac832f15eff047a5b4100738af8dc205";
const uriBase =
  "https://australiaeast.api.cognitive.microsoft.com/face/v1.0/detect";
const params = {
  returnFaceId: "true",
  returnFaceLandmarks: "false",
  returnFaceAttributes:
    "age,gender,headPose,smile,facialHair,glasses,emotion,hair,makeup,occlusion,accessories,blur,exposure,noise"
};
